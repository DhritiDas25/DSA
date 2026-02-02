//1. Find sum of all array elements using recursion.
#include<stdio.h>
int sum(int arr[], int n)
{
    if(n==0)
    {return 0;}
    else{
        return arr[n-1]+sum(arr,n-1);
    }
}
int main()
{
    int n,i,s;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    s=sum(arr,n);
    printf("Sum: %d\n", s);
}