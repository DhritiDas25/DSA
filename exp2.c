/* 2.Create an array ‘a1’ with ‘n’ elements.
Insert an element in ith position of ‘a1’ and also 
delete an element from jth position of ‘a1’.*/
#include<stdio.h>
int main(){
    int i,j,k,n,a;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int a1[100];
    printf("Enter elements: ");
    for(k=0;k<n;k++)
    {
        scanf("%d", &a1[k]);
    }
    printf("Input a posn. 0-%d: ", n);
    scanf("%d", &i);
    printf("Input a random no.: ");
    scanf("%d", &a);
    for(k=n;k>=i;k--)
    {
        a1[k]=a1[k-1];
    }
    a1[i-1]=a;
    n++;
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &j);
    for(k=j-1;k<n-1;k++)
    {
        a1[k] = a1[k+1];
    }
    n--;
    printf("The array: ");
    for(k=0;k<n;k++)
    {
        printf("%d ", a1[k]);
    }
    return 0;
}
