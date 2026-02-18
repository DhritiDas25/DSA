/* LAB:
1. Implement single Linked List data structure and its operations like insert and 
delete in the beginning/end and nth position of the list, and display the items 
stored in the linked list.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int val, int pos) {
    struct Node *newN = malloc(sizeof(struct Node)), *temp = *head;
    newN->data = val;
    if (pos == 1) { newN->next = *head; *head = newN; return; }
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) return;
    newN->next = temp->next;
    temp->next = newN;
}
void delete(struct Node** head, int pos) {
    if (!*head) return;
    struct Node *temp = *head, *prev;
    if (pos == 1) { *head = temp->next; free(temp); return; }
    for (int i = 1; temp && i < pos; i++) { prev = temp; temp = temp->next; }
    if (!temp) return;
    prev->next = temp->next;
    free(temp);
}
void display(struct Node* head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    insert(&head, 10, 1); // Start
    insert(&head, 30, 2); // End
    insert(&head, 20, 2); // Nth
    display(head);        // 10 -> 20 -> 30 -> NULL
    delete(&head, 2);     // Delete Nth
    display(head);        // 10 -> 30 -> NULL
    return 0;
}