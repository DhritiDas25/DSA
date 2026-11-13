
#include <stdio.h>

struct Activity {
    int start;
    int finish;
};

int main() {
    struct Activity a[100], temp;
    int n, i, j;
    int lastFinish;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter start and finish time of activity %d: ", i + 1);
        scanf("%d %d", &a[i].start, &a[i].finish);
    }

    // Sort activities by finishing time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j].finish > a[j + 1].finish) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nSelected activities:\n");

    // Select the first activity
    lastFinish = a[0].finish;
    printf("(%d, %d)\n", a[0].start, a[0].finish);

    // Select compatible activities
    for (i = 1; i < n; i++) {
        if (a[i].start >= lastFinish) {
            printf("(%d, %d)\n", a[i].start, a[i].finish);
            lastFinish = a[i].finish;
        }
    }

    return 0;
}