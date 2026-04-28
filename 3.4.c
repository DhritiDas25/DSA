/*Evaluate postfix expression using stack and array.*/
#include<stdio.h>
#include<string.h>
#define max 20
int stack[max],top=-1;
void push(int x){
    if(top==max-1)
    {
        printf("Stack overflow\n");
    }
    else{
        stack[++top]=x;
    }
}
int pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return 0;
    }
    else{
        return stack[top--];
    }
}
int main(){
    char exp[20];
    int n1,n2,i,res;
    printf("Enter postfix exp: ");
    fgets(exp,sizeof(exp),stdin);
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]==' '||exp[i]=='\n'||exp[i]=='\r'){
            continue;
        }
        if(exp[i]>='0' && exp[i]<='9'){
            push(exp[i]-'0');
        }
        else{
            n2=pop();
            n1=pop();
            if(exp[i]=='+')res=n1+n2;
            else if(exp[i]=='-')res=n1-n2;
            else if(exp[i]=='*')res=n1*n2;
            else if(exp[i]=='/')res=n1/n2;
            else if(exp[i]=='%')res=n1%n2;
            push(res);
        }
    }
    printf("Result: %d\n", pop());
    return 0;
}