#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *newNode(int new_data) {
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = NULL;

    return new_node;
}

void sortedInsert(struct Node **head_ref, struct Node *new_node) {
    struct Node *current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != NULL &&
               current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(struct Node *head) {
    for(;head; head = head->next){
        printf("%d ", head->data);
    }
    puts("");
}

int main() {
    struct Node *head = NULL;
    struct Node *new_node = NULL;
    int n;
    while (scanf("%d", &n),n != -1) {
        new_node = newNode(n);
        sortedInsert(&head, new_node);
        printList(head);
    }
    printList(head);

    return 0;
}