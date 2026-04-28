/*2. Using single linked list and functions implement Stack and its operations like insert, delete,
and display.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
// Push: Insert at the beginning
void push(struct Node** top, int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) return; 
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d\n", val);
}
// Pop: Delete from the beginning
void pop(struct Node** top) {
    if (*top == NULL) { printf("Stack Underflow\n"); return; }
    struct Node* temp = *top;
    printf("Popped %d\n", temp->data);
    *top = (*top)->next;
    free(temp);
}
// Display the stack
void display(struct Node* top) {
    if (!top) { printf("Stack is empty\n"); return; }
    while (top) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(stack); // 30 -> 20 -> 10 -> NULL
    pop(&stack);
    display(stack); // 20 -> 10 -> NULL
    return 0;
}