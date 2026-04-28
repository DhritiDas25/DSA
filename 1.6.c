/*6. Store ‘n’ numbers (integers or real) in an array.  
Conduct a linear search for a given number and report success or
failure in the form of a suitable message.*/
#include<stdio.h>
int main(){
    int ind=0,i,n,ele,flag=0;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int a1[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a1[i]);
    }
    printf("Enter an element to search: ");
    scanf("%d", &ele);
    for(i=0;i<n;i++)
    {
        if(ele==a1[i])
        {
            flag=1;
            ind=i;
            break;
        }
    }
    if(flag==1)
    { printf("Element %d found at position %d\n", ele, ind+1);}
    else
    { printf("No element %d found\n", ele);}
    return 0;
}