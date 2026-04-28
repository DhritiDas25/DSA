/*1. Using array and functions implement Circular Queue data structure and its operations like insert, delete, and display.*/
#include <stdio.h>
#define MAX 5
int cqueue[MAX], front = -1, rear = -1;
void insert(int val) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cqueue[rear] = val;
    }
}
void delete() {
    if (front == -1) {
        printf("Queue Empty\n");
    } else {
        printf("Deleted %d\n", cqueue[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }
}
void display() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }
    int i = front;
    printf("Circular Queue: ");
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    insert(1); insert(2); insert(3); insert(4); insert(5);
    delete();
    insert(6);
    display();
    return 0;
}