def optimized_bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        swapped = False

        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        if not swapped:
            break

    return arr


n = int(input("Enter number of elements: "))
arr = []

print("Enter array elements:")
for i in range(n):
    arr.append(int(input()))

print("Sorted array:", optimized_bubble_sort(arr))