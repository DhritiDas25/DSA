
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {

    // Base condition: element not found
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    // Element found
    if (arr[mid] == key) {
        return mid;
    }

    // Search right half
    else if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, high, key);
    }

    // Search left half
    else {
        return binarySearch(arr, low, mid - 1, key);
    }
}

int main() {
    int arr[100], n, i, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if (result == -1) {
        printf("Element not found");
    } else {
        printf("Element found at position %d", result + 1);
    }

    return 0;
}