/*2. Using array and functions implement a Stack using Queues.*/
#include <stdio.h>

#define MAX 20
int q1[MAX], q2[MAX];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;

void enqueue(int* q, int* f, int* r, int val) {
    if (*r == MAX - 1) return;
    if (*f == -1) *f = 0;
    q[++(*r)] = val;
}

int dequeue(int* q, int* f, int* r) {
    if (*f == -1 || *f > *r) return -1;
    int val = q[(*f)++];
    if (*f > *r) *f = *r = -1;
    return val;
}

void push(int val) {
    enqueue(q1, &f1, &r1, val);
}

int pop() {
    if (f1 == -1) return -1;
    while (f1 < r1) {
        enqueue(q2, &f2, &r2, dequeue(q1, &f1, &r1));
    }
    int popped = dequeue(q1, &f1, &r1);
    // Swap queues
    int* tempQ = q1; // Simplified logic for demo
    // In a full implementation, you'd swap pointers or move data back
    while (f2 != -1) {
        enqueue(q1, &f1, &r1, dequeue(q2, &f2, &r2));
    }
    return popped;
}

int main() {
    push(1); push(2); push(3);
    printf("Popped: %d\n", pop()); // Should be 3
    printf("Popped: %d\n", pop()); // Should be 2
    return 0;
}