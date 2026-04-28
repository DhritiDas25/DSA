/*2. Perform operations such as insertion and deletion on the heap.*/
#include <stdio.h>

int heap[100];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val) {
    size++;
    int i = size - 1;
    heap[i] = val;

    // Operation: Heapify Up
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void deleteRoot() {
    if (size == 0) return;
    printf("Deleting root: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    // Operation: Heapify Down
    int i = 0;
    while (1) {
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;
        if (largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}
int main() {
    insert(40);
    insert(50);
    insert(30);
    insert(100);
    printf("After Insertions: ");
    for(int i=0; i<size; i++) printf("%d ", heap[i]);
    printf("\n");
    deleteRoot();
    printf("After Deletion: ");
    for(int i=0; i<size; i++) printf("%d ", heap[i]);
    printf("\n");
    return 0;
}
