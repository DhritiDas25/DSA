/*1. WAP to implement linear and binary search algorithms*/
#include <stdio.h>

// Linear Search: Scans one by one
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Binary Search: Divides interval in half (Requires Sorted Array)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Simple Selection Sort to prepare array for Binary Search
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter value to search: ");
    scanf("%d", &key);

    // 1. Run Linear Search (on unsorted array)
    int resL = linearSearch(arr, n, key);
    printf("\n[Linear Search] Result: ");
    if (resL != -1) printf("Found at index %d\n", resL);
    else printf("Not Found\n");

    // 2. Sort and Run Binary Search
    sort(arr, n);
    printf("\nSorted array for Binary Search: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    int resB = binarySearch(arr, n, key);
    printf("\n[Binary Search] Result: ");
    if (resB != -1) printf("Found at index %d\n", resB);
    else printf("Not Found\n");

    return 0;
}
