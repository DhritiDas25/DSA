/* 1. Using array and functions implement Stack and its operations like insert, delete, and display.*/
#include<stdio.h>
#define s 5
int i,stack[100],top=-1;
void push(int value){
    if(top==s-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=value;
    }
}
void pop()
{
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Deleted %d\n", stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1){
        printf("Stack Empty\n");
    }
    else{
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
int main(){
    push(30);
    push(10);
    push(50);
    display();
    pop();
    display();
    return 0;
}