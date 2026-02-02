//4. Find the sum of rows and columns of matrix of given order (row x column).
#include <stdio.h>

int main() {
    int row, col;
    int i, j;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    int matrix[row][col];
    printf("Enter matrix elements:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nSum of each row:\n");
    for (i = 0; i < row; i++) {
        int rowSum = 0;
        for (j = 0; j < col; j++) {
            rowSum += matrix[i][j];
        }
        printf("Row %d = %d\n", i + 1, rowSum);
    }
    printf("\nSum of each column:\n");
    for (j = 0; j < col; j++) {
        int colSum = 0;
        for (i = 0; i < row; i++) {
            colSum += matrix[i][j];
        }
        printf("Column %d = %d\n", j + 1, colSum);
    }
    return 0;
}
