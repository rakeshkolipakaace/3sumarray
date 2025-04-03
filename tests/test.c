#include <stdio.h>
#include <stdlib.h>

// Declare the function from solution.c
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

// Function to print the output
void printResult(int** result, int returnSize, int* returnColumnSizes) {
    printf("[\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  [");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
    }
    printf("]\n");
}

// Function to free allocated memory
void freeResult(int** result, int returnSize, int* returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
}

int main() {
    int returnSize;
    int* returnColumnSizes;

    int testCases[][6] = {
        {-1, 0, 1, 2, -1, -4},  // Test Case 1
        {0, 1, 1},              // Test Case 2
        {0, 0, 0},              // Test Case 3
        {1, 2, -3},             // Test Case 4
        {1, 1, 1, 1},           // Test Case 5
    };

    int testSizes[] = {6, 3, 3, 3, 4};
    int numTests = sizeof(testSizes) / sizeof(testSizes[0]);

    for (int i = 0; i < numTests; i++) {
        printf("Test Case %d:\n", i + 1);
        int** result = threeSum(testCases[i], testSizes[i], &returnSize, &returnColumnSizes);
        printResult(result, returnSize, returnColumnSizes);
        freeResult(result, returnSize, returnColumnSizes);
    }

    return 0;
}
