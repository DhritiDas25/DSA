/* 2. Reverse a string using stack.*/
#include<stdio.h>
#include<string.h>
int i;
void rev(char string[]){
    int top=strlen(string)-1;
    if(string[top]=='\n'){
        top--;
    }
    if(top<0){
        printf("Stack Empty\n");
    }
    else{
        printf("Reversed String: ");
        for(i=top;i>=0;i--){
            printf("%c", string[i]);
        }
        printf("\n");
    }
}
int main(){
    char string[100];
    printf("Enter a string: ");
    fgets(string,sizeof(string),stdin);
    rev(string);
    return 0;
}