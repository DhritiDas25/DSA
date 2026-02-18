#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;

// Create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at Beginning
void insertBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at End
void insertEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Delete from Beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    if (head->next == NULL) {
        head = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

// Delete from End
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    if (head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Display Forward
void displayForward() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display Backward
void displayBackward() {
    struct Node* temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
// Main Function
int main() {
    insertBeginning(10);
    insertBeginning(5);
    insertEnd(20);
    insertEnd(30);
    printf("Forward: ");
    displayForward();
    printf("Backward: ");
    displayBackward();
    deleteBeginning();
    deleteEnd();
    printf("After Deletion: ");
    displayForward();
    return 0;
}