/*1. Convert infix to postfix expression using stack and array.*/
#include<stdio.h>
#include<string.h>
int i,j;
void postfix(char arr[]){
    int top=strlen(arr)-1;
    if(arr[top]=='\n'){
        top--;
    }
    if(top<0){
        printf("Stack empty\n");
    }
    else{
        for(i=top;i>=0;i--){
            if(arr[i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/'||arr[i]=='%'){
                char j=arr[i];
            }
            else{
                printf("%c ", arr[i]);
            }
    }
    printf("%c\n", j);
}
}
int main(){
    char arr[100];
    printf("Enter infix expression: ");
    fgets(arr,sizeof(arr),stdin);
    postfix(arr);
    return 0;
}