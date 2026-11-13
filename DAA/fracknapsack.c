
#include <stdio.h>

struct Item {
    float profit;
    float weight;
    float ratio;
};

int main() {
    struct Item item[100], temp;
    int n, i, j;
    float capacity, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++) {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%f %f", &item[i].profit, &item[i].weight);

        if (item[i].weight <= 0) {
            printf("Weight must be positive.\n");
            return 1;
        }

        item[i].ratio = item[i].profit / item[i].weight;
    }

    // Sort items by decreasing profit-to-weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (item[j].ratio < item[j + 1].ratio) {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }

    // Select items greedily
    for (i = 0; i < n; i++) {

        if (capacity == 0) {
            break;
        }

        if (item[i].weight <= capacity) {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        }
        else {
            totalProfit += item[i].ratio * capacity;
            capacity = 0;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
