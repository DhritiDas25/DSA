def kadane(arr):
    current_sum = arr[0]
    max_sum = arr[0]

    for i in range(1, len(arr)):
        if current_sum + arr[i] < arr[i]:
            current_sum = arr[i]
        else:
            current_sum += arr[i]

        if current_sum > max_sum:
            max_sum = current_sum

    return max_sum
n = int(input("Enter number of elements: "))
arr = []

print("Enter array elements:")
for i in range(n):
    arr.append(int(input()))

if n == 0:
    print("Array cannot be empty")
else:
    print("Maximum subarray sum:", kadane(arr))