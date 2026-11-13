
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {
            i++;
        }
        else {
            int value = arr[j];
            int index = j;

            // Shift elements to the right
            while (index > i) {
                arr[index] = arr[index - 1];
                index--;
            }

            arr[i] = value;

            i++;
            mid++;
            j++;
        }
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}