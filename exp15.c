/*Evaluate postfix expression using stack and array.*/
#include<stdio.h>
int stack[20],top=-1;
void push(int x){
    if(top==)
    {

    }
    stack[++top]=x;
}
int pop(){
    if(top==-1){
        Print("Stack Underflow\n");
    }
    else{
        return stack[top--];
    }
}
int main(){
    char exp[20];
    int n1,n2,i,r;
    printf("Enter postfix exp: ");
    scanf("%s", &exp[i]);
    n1=pop();
    n2=pop();
}
