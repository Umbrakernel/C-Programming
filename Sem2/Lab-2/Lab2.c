#include <stdio.h>
#include <stdlib.h>

// Структура узла
typedef struct Node {
    int data;
    struct Node* next;  // Указатель на следующий узел (горизонтальная связь)
    struct Node* down;  // Указатель на нижний узел (вертикальная связь)
} Node;

// Указатель на начало верхнего списка
Node* S = NULL;

// Функция создания нового узла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->down = NULL;
    return newNode;
}

// Функция добавления узла в конец списка
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Функция вывода списка
void printList(Node* head) {
    while (head) {
        printf("[%d] -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Функция создания списка по схеме
void createStructuredList() {
    // Создаем верхний список
    S = createNode(6);
    append(&S, 5);
    append(&S, 4);
    append(&S, 3);
    append(&S, 2);
    append(&S, 1);

    // Создаем нижний список
    Node* lower = createNode(0);
    append(&lower, 1);

    // Связываем верхний и нижний списки
    Node* upper = S;
    Node* lowerPtr = lower;

    while (upper && lowerPtr) {
        upper->down = lowerPtr;
        upper = upper->next;
        lowerPtr = lowerPtr->next;
    }

    // Выводим оба списка
    printf("Верхний список: ");
    printList(S);
    printf("Нижний список: ");
    printList(lower);
}

// Функция навигации по списку
void navigateList() {
    Node* current = S;
    char command;

    printf("Управление: 'd' - вправо, 's' - вниз, 'w' - вверх, 'r' - в начало, 'q' - выход\n");

    while (1) {
        printf("Текущий элемент: %d\n", current->data);
        scanf(" %c", &command);

        if (command == 'd' && current->next) {
            current = current->next;
        } else if (command == 's' && current->down) {
            current = current->down;
        } else if (command == 'w') {
            printf("Перемещение вверх невозможно (односвязный список)\n");
        } else if (command == 'r') {
            current = S;
            printf("Вернулись в начало списка\n");
        } else if (command == 'q') {
            break;
        } else {
            printf("Невозможно выполнить команду\n");
        }
    }
}

// Функция освобождения памяти
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    createStructuredList();
    navigateList();
    freeList(S);
    return 0;
}