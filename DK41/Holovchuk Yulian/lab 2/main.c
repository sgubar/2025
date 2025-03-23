#include "my_list.h"

int main() {
    Node* head = NULL; 
    int num;
    char input[100];

    printf("Enter integer number for the list (type 's' to stop input):\n");

    while (1) {
        printf("Enter a number: ");
        fgets(input, sizeof(input), stdin); 

        if (input[0] == 's' && input[1] == '\n') {
            break;
        }

        int i = 0, negative = 0;
        if (input[i] == '-') { 
            negative = 1;
            i++;
        }

        for (; input[i] != '\0' && input[i] != '\n'; i++) {
            if (input[i] < '0' || input[i] > '9') { 
                printf("Invalid input! Please enter a valid integer or 's' to stop.\n");
                continue;
            }
        }

        if (input[i] == '\n' && i > (negative ? 1 : 0)) {
            sscanf(input, "%d", &num);
            append(&head, num);
        }
    }
    
    if (head == NULL) {
        printf("The list is empty!\n");
        return 0;
    }
    
    printList(head);
    double average = calculateAverage(head);
    printf("Average: %.2f\n", average);
    removeFirstBelowAverage(&head, average);
    printList(head);

    freeList(head); // Звільнення пам’яті
    return 0;
}
