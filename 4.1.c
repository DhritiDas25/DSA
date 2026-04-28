/*1. Using array and functions implement Queue data structure and its operations like insert, delete, and display.*/
#include <stdio.h>
#define MAX 50

int queue[MAX], front = -1, rear = -1;

void insert(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = val;
        printf("Inserted %d\n", val);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted %d\n", queue[front++]);
        if (front > rear) front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    insert(10); insert(20); insert(30);
    display();
    delete();
    display();
    return 0;
}