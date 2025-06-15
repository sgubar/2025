 /* lab2.c
 * Laboratory Work No.2: Linked Lists
 * Tasks:
 *  1) Create a linear singly linked list and display it.
 *  2) Convert the list into a circular linked list.
 *  3) In the circular list, remove every third element until fewer than three remain,
 *     showing each removal.
 */

#include <stdio.h>
#include <stdlib.h>

// Node of singly linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Clear input buffer after bad scanf
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Read integer with prompt and validation
int read_int(const char *prompt) {
    int x, ok;
    do {
        printf("%s", prompt);
        ok = scanf("%d", &x);
        if (ok != 1) {
            printf("  Error: enter a valid integer.\n");
            clear_buffer();
        }
    } while (ok != 1);
    clear_buffer();
    return x;
}

// Append value to end of list
void append(Node **head, int value) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(1); }
    n->data = value;
    n->next = NULL;
    if (*head == NULL) {
        *head = n;
    } else {
        Node *p = *head;
        while (p->next) p = p->next;
        p->next = n;
    }
}

// Print (linear or circular) list
void print_list(Node *head) {
    if (!head) {
        printf("  (empty)\n");
        return;
    }
    Node *p = head;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p && p != head);
    printf("\n");
}

// Make list circular
void make_circular(Node *head) {
    if (!head) return;
    Node *p = head;
    while (p->next) p = p->next;
    p->next = head;
}

// Remove node after prev in circular list
void remove_after(Node *prev) {
    Node *to = prev->next;
    prev->next = to->next;
    free(to);
}

// Remove every k-th until count < m
void remove_every_kth(Node **head, int k, int m) {
    if (!*head) return;
    // find tail
    Node *prev = *head;
    while (prev->next != *head) prev = prev->next;
    // count
    int cnt = 0;
    Node *t = *head;
    do { cnt++; t = t->next; } while (t != *head);
    // eliminate
    while (cnt >= m) {
        for (int i = 1; i < k; i++) prev = prev->next;
        printf("Removing: %d\n", prev->next->data);
        remove_after(prev);
        cnt--;
        *head = prev->next;
        printf("Current list: ");
        print_list(*head);
    }
}

int main() {
    printf("=== Lab 2: Linked Lists ===\n");
    int n;
    do {
        n = read_int("Enter number of elements (>=1): ");
        if (n < 1) printf("  Error: must be >=1.\n");
    } while (n < 1);

    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        char buf[50];
        sprintf(buf, "  Element #%d: ", i+1);
        int v = read_int(buf);
        append(&head, v);
    }

    printf("\nLinear list: ");
    print_list(head);

    make_circular(head);
    printf("\n--- Removing every 3rd element ---\n");
    remove_every_kth(&head, 3, 3);

    printf("\nFinal (fewer than 3 left): ");
    print_list(head);

    // free
    if (head) {
        head->next = NULL;
        while (head) {
            Node *nx = head->next;
            free(head);
            head = nx;
        }
    }
    return 0;
}
