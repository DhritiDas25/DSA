def merge_inplace(arr, left, mid, right):
    i = left
    j = mid + 1

    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            i += 1
        else:
            value = arr[j]
            index = j

            while index > i:
                arr[index] = arr[index - 1]
                index -= 1

            arr[i] = value

            i += 1
            mid += 1
            j += 1

def inplace_merge_sort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2

        inplace_merge_sort(arr, left, mid)
        inplace_merge_sort(arr, mid + 1, right)

        merge_inplace(arr, left, mid, right)


n = int(input("Enter number of elements: "))
arr = []
print("Enter array elements:")
for i in range(n):
    arr.append(int(input()))

inplace_merge_sort(arr, 0, n - 1)

print("Sorted array:", arr)