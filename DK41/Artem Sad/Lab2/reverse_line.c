#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define MAX_buffer_LENGTH 1024

typedef struct Vuzl {
    char *data;
    struct Vuzl *next;
} Vuzl;

void add_Vuzl(Vuzl **list_head, char *buffer) {
    Vuzl *new_Vuzl = (Vuzl *)malloc(sizeof(Vuzl));
    if (!new_Vuzl) {
        printf("Помилка виділення памяті\n");
        exit(1);
    }
    
    new_Vuzl->data = strdup(buffer);
    if (!new_Vuzl->data) {
        printf("Помилка виділення памяті\n");
        free(new_Vuzl);
        exit(1);
    }
    
    new_Vuzl->next = *list_head;
    *list_head = new_Vuzl;
}

void print_spus_revers(Vuzl *list_head) {
    while (list_head != NULL) {
        printf("%s\n", list_head->data);
        list_head = list_head->next;
    }
}

void del_spus_revers(Vuzl *list_head) {
    while (list_head != NULL) {
        Vuzl *swap = list_head;
        list_head = list_head->next;
        free(swap->data);
        free(swap);
    }
}

void reverse_buffer(char *buffer) {
    char *start_revers = buffer;
    char *end_revers = buffer + strlen(buffer) - 1;
    
    while (start_revers < end_revers) {
        char swap = *start_revers;
        *start_revers = *end_revers;
        *end_revers = swap;
        start_revers++;
        end_revers--;
    }
}

int is_valid_filename(const char *filename) {
    if (!filename || *filename == '\0') return 0;
    
    while (*filename) {
        if (!isalnum(*filename) && *filename != '.' && *filename != '-' && *filename != '_') {
            return 0;
        }
        filename++;
    }
    return 1;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    char filename[MAX_buffer_LENGTH];
    Vuzl *spus_revers = NULL;
    
    printf("Введіть імя файлу: ");
    if (!fgets(filename, MAX_buffer_LENGTH, stdin)) {
        printf("Помилка читання введення\n");
        return 1;
    }

    filename[strcspn(filename, "\n")] = '\0';

    if (!is_valid_filename(filename)) {
        printf("Недопустиме імя файлу\n");
        return 1;
    }
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Помилка відкриття файлу.\n");
        return 1;
    }
    
    char buffer[MAX_buffer_LENGTH];
    while (fgets(buffer, MAX_buffer_LENGTH, file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        reverse_buffer(buffer);
        add_Vuzl(&spus_revers, buffer);
    }
    
    fclose(file);
    
    printf("\nРезультат:\n");
    print_spus_revers(spus_revers);
    del_spus_revers(spus_revers);
    
    return 0;
}
