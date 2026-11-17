def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr


n = int(input("Enter number of elements: "))
arr = []

print("Enter array elements:")
for i in range(n):
    arr.append(int(input()))

print("Sorted array:", bubble_sort(arr))

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}