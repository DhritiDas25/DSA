def fractional_knapsack(items, capacity):
    n = len(items)

    # Sort by profit/weight ratio using Bubble Sort
    for i in range(n - 1):
        for j in range(n - i - 1):
            ratio1 = items[j][0] / items[j][1]
            ratio2 = items[j + 1][0] / items[j + 1][1]

            if ratio1 < ratio2:
                items[j], items[j + 1] = items[j + 1], items[j]

    total_profit = 0

    for profit, weight in items:
        if capacity == 0:
            break

        if weight <= capacity:
            total_profit += profit
            capacity -= weight

        else:
            fraction = capacity / weight
            total_profit += profit * fraction
            capacity = 0

    return total_profit


n = int(input("Enter number of items: "))
items = []

for i in range(n):
    print("Enter profit and weight of item", i + 1)
    profit = float(input("Profit: "))
    weight = float(input("Weight: "))
    items.append((profit, weight))

capacity = float(input("Enter knapsack capacity: "))

if any(weight <= 0 for profit, weight in items) or capacity < 0:
    print("Invalid weight or capacity")
else:
    result = fractional_knapsack(items, capacity)
    print("Maximum profit:", result)