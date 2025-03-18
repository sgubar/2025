#include <stdio.h>
#include "dk_tool.h"

// Функція для введення рядка з консолі
void input_string(char *buffer, int size, const char *prompt)
{
    printf("%s", prompt);
    if (scanf("%s", buffer) != 1) {
        fprintf(stderr, "Помилка введення\n");
    }
}

int main(void)
{
    char oct_input[10];
    
    // Запитуємо у користувача восьмкове число
    input_string(oct_input, sizeof(oct_input), "Введіть вісімкове число: ");

    int value = oct_to_int(oct_input);
    if (value == -1) {
        printf("Помилка перетворення.\n");
    } else {
        printf("Десяткове значення: %d\n", value);
    }

    return 0;
}
