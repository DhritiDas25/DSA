
#include <stdio.h>

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    // Compare elements from both halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right half
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy merged elements back into original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);

        merge(arr, temp, left, mid, right);
    }
}

int main() {
    int arr[100], temp[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, temp, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}