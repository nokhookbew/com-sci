#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void insertNode(struct Node **head, int new_value) {
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    new_node->value = new_value;
    new_node->next = NULL;

    if (*head == NULL || (*head)->value >= new_node->value) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct Node *current = *head;
        while (current->next != NULL &&
               current->next->value < new_node->value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(struct Node *head) {
    for(;head; head = head->next){
        printf("%d ", head->value);
    }
    puts("");
}

int main() {
    struct Node *head = NULL;
    int n;
    while (scanf("%d", &n),n != -1) {
        insertNode(&head, n);
        printList(head);
    }
    printList(head);

    return 0;
}