//#include <stdio.h>
//#include <stdlib.h>


struct Matrix {
    int rows;
    int cols;
    int **data; 
};
int main() {
    struct Matrix m;
    int i, j;

    // Input 
    printf("Enter number of rows: ");
    scanf("%d", &m.rows);
    printf("Enter number of columns: ");
    scanf("%d", &m.cols);

    // Dynamically allocate memory for rows
    m.data = (int **)malloc(m.rows * sizeof(int *));
    if (m.data == NULL) {
        printf("Memory allocation failed for rows!\n");
        return 1;
    }

    // Dynamically allocate memory for columns in each row
    for (i = 0; i < m.rows; i++) {
        m.data[i] = (int *)malloc(m.cols * sizeof(int));
        if (m.data[i] == NULL) {
            printf("Memory allocation failed for columns!\n");
            return 1;
        }
    }

    // Input elements into the 2D array
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            scanf("%d", &m.data[i][j]);
        }
    }

    // Display the 2D array
    printf("The matrix is:\n");
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);

    return 0;
}
