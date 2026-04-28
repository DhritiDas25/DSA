/*1. Convert infix to postfix expression using stack and array.*/
#include <stdio.h>
#include <ctype.h>
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
int main() {
    char infix[100], stack[100];
    int top = -1;
    printf("Enter expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            printf("%c", infix[i]);
        } 
        else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                printf("%c", stack[top--]);
            }
            stack[++top] = infix[i]; 
        }
    }
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    return 0;
}