#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translator_utils.h"

DictionaryEntry* load_dictionary(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Не удалось открыть словарь");
        exit(1);
    }

    int capacity = 64; //обем словаря
    *size = 0;
    DictionaryEntry* dict = malloc(capacity * sizeof(DictionaryEntry));
    if (!dict) {
        perror("Ошибка выделения памяти под словарь");
        exit(1);
    }

    char rus[MAX_WORD], chn[MAX_WORD];
    while (fscanf(file, "%s %s", rus, chn) == 2) {
        if (*size >= capacity) {
            capacity *= 2;
            dict = realloc(dict, capacity * sizeof(DictionaryEntry));
        }
        dict[*size].rus = strdup(rus); //strdup делает копию строки в новой памяти — чтобы не стерлась позже.
        dict[*size].chn = strdup(chn);
        (*size)++;
    }

    fclose(file);
    return dict;
}

const char* find_translation(const char* word, DictionaryEntry* dict, int size) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(word, dict[i].rus) == 0) {
            return dict[i].chn;
        }
    }
    return NULL;
}

int is_utf8_letter_start(unsigned char c) { //можем ли считать байт началом utf-8 символа
    return (c >= 0xC0) || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); //с >= 0xC0. байты начала многобайтных UTF-8 символов. Символы в UTF-8 могут начинаться с байтов от 0xC0 и выше
}

int utf8_char_len(unsigned char c) {
    if ((c & 0x80) == 0) return 1;
    else if ((c & 0xE0) == 0xC0) return 2;
    else if ((c & 0xF0) == 0xE0) return 3;
    else return 1;
}

void process_line(char* line, FILE* out, DictionaryEntry* dict, int dict_size) {
    int i = 0;
    while (line[i]) {
        if (!is_utf8_letter_start((unsigned char)line[i])) {
            fputc(line[i], out);
            i++;
            continue;
        }

        char word[MAX_WORD] = {0};
        int w = 0;

        while (line[i] && is_utf8_letter_start((unsigned char)line[i])) {
            int len = utf8_char_len((unsigned char)line[i]);
            if (w + len >= MAX_WORD) break;//Границы буфера
            strncpy(&word[w], &line[i], len);//копируем символ (все его байты) в word, сдвигаемся дальше в line.
            i += len;
            w += len;
        }
        word[w] = '\0';

        const char* trans = find_translation(word, dict, dict_size);
        if (trans)
            fputs(trans, out);
        else
            fputs(word, out);
    }
}
