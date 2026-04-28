/*2. Check whether the string is palindrome or not using array and Queue.*/
#include <stdio.h>
#include <string.h>

#define MAX 100
char queue[MAX];
int front = -1, rear = -1;

void enqueue(char c) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = c;
}

char dequeue() {
    if (front == -1 || front > rear) return '\0';
    return queue[front++];
}

int main() {
    char str[MAX];
    int isPalindrome = 1;

    printf("Enter string: ");
    // Fix: Using fgets to read spaces
    fgets(str, MAX, stdin);
    
    // Remove newline character added by fgets
    str[strcspn(str, "\n")] = 0;

    int len = strlen(str);

    for (int i = 0; i < len; i++) enqueue(str[i]);

    for (int i = 0; i < len; i++) {
        if (dequeue() != str[len - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) printf("The string is a palindrome.\n");
    else printf("The string is not a palindrome.\n");

    return 0;
}
