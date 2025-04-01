#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    double salary;
    char phone[20];
} Employee;

void add_employees() {
    FILE *f = fopen("Work.dat", "wb");
    if (!f) {
        printf("Ошибка создания файла\n");
        return;
    }

    int count;
    printf("Сколько сотрудников добавить? ");
    scanf("%d", &count);
    getchar(); // очистка буфера

    for (int i = 0; i < count; i++) {
        Employee e;
        printf("\nСотрудник %d:\n", i+1);
        printf("ФИО: "); 
        fgets(e.name, 100, stdin);
        e.name[strlen(e.name)-1] = '\0'; // удаляем \n
        
        printf("Зарплата: ");
        scanf("%lf", &e.salary);
        getchar();
        
        printf("Телефон: ");
        fgets(e.phone, 20, stdin);
        e.phone[strlen(e.phone)-1] = '\0';
        
        fwrite(&e, sizeof(Employee), 1, f);
    }
    
    fclose(f);
    printf("\nДанные сохранены в Work.dat\n");
}

void search_employee() {
    FILE *f = fopen("Work.dat", "rb");
    if (!f) {
        printf("Файл не найден\n");
        return;
    }

    printf("\nПоиск по:\n1. ФИО\n2. Зарплате\n3. Телефону\nВыбор: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    Employee e;
    int found = 0;
    
    if (choice == 1) {
        char name[100];
        printf("Введите ФИО: ");
        fgets(name, 100, stdin);
        name[strlen(name)-1] = '\0';
        
        while (fread(&e, sizeof(Employee), 1, f)) {
            if (strcmp(e.name, name) == 0) {
                printf("\nНайдено:\nФИО: %s\nЗарплата: %.2lf\nТелефон: %s\n", 
                      e.name, e.salary, e.phone);
                found = 1;
            }
        }
    }
    else if (choice == 2) {
        double salary;
        printf("Введите зарплату: ");
        scanf("%lf", &salary);
        
        while (fread(&e, sizeof(Employee), 1, f)) {
            if (e.salary == salary) {
                printf("\nНайдено:\nФИО: %s\nЗарплата: %.2lf\nТелефон: %s\n", 
                      e.name, e.salary, e.phone);
                found = 1;
            }
        }
    }
    else if (choice == 3) {
        char phone[20];
        printf("Введите телефон: ");
        fgets(phone, 20, stdin);
        phone[strlen(phone)-1] = '\0';
        
        while (fread(&e, sizeof(Employee), 1, f)) {
            if (strcmp(e.phone, phone) == 0) {
                printf("\nНайдено:\nФИО: %s\nЗарплата: %.2lf\nТелефон: %s\n", 
                      e.name, e.salary, e.phone);
                found = 1;
            }
        }
    }

    if (!found) printf("Ничего не найдено\n");
    fclose(f);
}

int main() {
    add_employees();
    search_employee();
    return 0;
}