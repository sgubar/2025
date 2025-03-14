// dk_tool.c - файл с реализацией функций
// Здесь содержится вся основная логика программы

#include "dk_tool.h"

// Функция проверяет корректность введенного числа
// Проверяет, что строка содержит только цифры и не превышает 4 символов
bool validate_input(const char* str) {
    int len = 0;  // счетчик количества символов
    
    // Проверяем каждый символ в строке
    while (*str != '\0' && *str != '\n') {
        // Проверяем, что символ является цифрой (от 0 до 9)
        if (!(*str >= '0' && *str <= '9')) {
            return false;  // если нашли не цифру - возвращаем false
        }
        len++;  // увеличиваем счетчик символов
        str++;  // переходим к следующему символу
    }
    
    // Возвращаем true, если строка не пустая и не превышает 4 символов
    return len > 0 && len <= 4;
}

// Функция преобразует строку в число
// Преобразует последовательность цифр в целое число
int str_to_num(const char* str) {
    int num = 0;  // результат преобразования
    
    // Перебираем все символы в строке
    while (*str != '\0' && *str != '\n') {
        // Преобразуем символ в цифру и добавляем к числу
        // Например, если число 123:
        // 1. num = 0 * 10 + (1 - '0') = 1
        // 2. num = 1 * 10 + (2 - '0') = 12
        // 3. num = 12 * 10 + (3 - '0') = 123
        num = num * 10 + (*str - '0');
        str++;  // переходим к следующему символу
    }
    
    return num;  // возвращаем полученное число
}
