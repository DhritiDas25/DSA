#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

// Create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at Beginning
void insertBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Insert at End
void insertEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

// Delete from Beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        struct Node* last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }
}

// Delete from End
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next->next != head)
            temp = temp->next;

        struct Node* last = temp->next;
        temp->next = head;
        free(last);
    }
}

// Display List
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Search
void search(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    int pos = 1;

    do {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element not found\n");
}

// Main Function
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertBeginning(5);

    display();

    deleteBeginning();
    deleteEnd();

    display();

    search(20);

    return 0;
}
