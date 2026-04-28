/*1. Implement a basic heap data structure.*/
#include <stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Core implementation of the heap property (Heapify Down)
void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    size = n;

    // Copy array to heap
    for(int i = 0; i < n; i++) heap[i] = arr[i];

    // Implementation: Convert array to Max-Heap
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(i);
    }

    printf("Heap Implementation: ");
    for (int i = 0; i < size; i++) printf("%d ", heap[i]);
    printf("\n");

    return 0;
}
