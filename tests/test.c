// #include <stdio.h>
// #include <stdlib.h>

// // Function prototype from solution.c
// int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

// // Function to print the output
// void printResult(int** result, int returnSize, int* returnColumnSizes) {
//     printf("[\n");
//     for (int i = 0; i < returnSize; i++) {
//         printf("  [");
//         for (int j = 0; j < returnColumnSizes[i]; j++) {
//             printf("%d", result[i][j]);
//             if (j < returnColumnSizes[i] - 1) printf(", ");
//         }
//         printf("]\n");
//     }
//     printf("]\n");
// }

// // Function to free allocated memory
// void freeResult(int** result, int returnSize, int* returnColumnSizes) {
//     for (int i = 0; i < returnSize; i++) {
//         free(result[i]);
//     }
//     free(result);
//     free(returnColumnSizes);
// }

// int main() {
//     int returnSize;
//     int* returnColumnSizes;

//     // Define test cases
//     int test1[] = {-1, 0, 1, 2, -1, -4};  // Expected: [[-1, -1, 2], [-1, 0, 1]]
//     int test2[] = {0, 1, 1};              // Expected: []
//     int test3[] = {0, 0, 0};              // Expected: [[0, 0, 0]]
//     int test4[] = {1, 2, -3};             // Expected: [[-3, 1, 2]]
//     int test5[] = {1, 1, 1, 1};           // Expected: []

//     int* tests[] = {test1, test2, test3, test4, test5};
//     int testSizes[] = {6, 3, 3, 3, 4};
//     int numTests = sizeof(testSizes) / sizeof(testSizes[0]);

//     for (int i = 0; i < numTests; i++) {
//         printf("Test Case %d:\n", i + 1);
//         int** result = threeSum(tests[i], testSizes[i], &returnSize, &returnColumnSizes);
//         printResult(result, returnSize, returnColumnSizes);
//         freeResult(result, returnSize, returnColumnSizes);
//     }

//     return 0;
// }








#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype from solution.c
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
    if (result == NULL) return;
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    if (returnColumnSizes) free(returnColumnSizes);
}

// Function to compare two arrays of arrays for equality
int areArraysEqual(int** expected, int expectedSize, int* expectedColumnSizes,
                   int** actual, int actualSize, int* actualColumnSizes) {
    if (expectedSize != actualSize) return 0;
    for (int i = 0; i < expectedSize; i++) {
        if (expectedColumnSizes[i] != actualColumnSizes[i]) return 0;
        for (int j = 0; j < expectedColumnSizes[i]; j++) {
            if (expected[i][j] != actual[i][j]) return 0;
        }
    }
    return 1;
}

// Helper function to create expected output
int** createExpected(int* triplets, int size) {
    if (size == 0) return NULL;
    int** result = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        result[i] = (int*)malloc(3 * sizeof(int));
        result[i][0] = triplets[i * 3];
        result[i][1] = triplets[i * 3 + 1];
        result[i][2] = triplets[i * 3 + 2];
    }
    return result;
}

void runTest(int* nums, int numsSize, int** expected, int expectedSize, int* expectedColumnSizes, int testNumber) {
    int returnSize;
    int* returnColumnSizes = NULL;

    printf("---------------------------------------------------\n");
    printf("Running: Test %d\n", testNumber);
    printf("Input: [");
    for (int j = 0; j < numsSize; j++) {
        printf("%d", nums[j]);
        if (j < numsSize - 1) printf(", ");
    }
    printf("]\n");

    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    printf("Actual Output: ");
    printResult(result, returnSize, returnColumnSizes);

    int passed = areArraysEqual(expected, expectedSize, expectedColumnSizes,
                              result, returnSize, returnColumnSizes);
    printf("Test %d: %s\n", testNumber, passed ? "✅ PASSED" : "❌ FAILED");

    freeResult(result, returnSize, returnColumnSizes);
    freeResult(expected, expectedSize, expectedColumnSizes);
}

int main() {
    // Define test cases
    struct {
        int* nums;
        int numsSize;
        int* expectedTriplets;
        int expectedSize;
        int* expectedColumnSizes;
    } tests[] = {
        { (int[]){-1, 0, 1, 2, -1, -4}, 6, (int[]){-1, -1, 2, -1, 0, 1}, 2, (int[]){3, 3} },
        { (int[]){0, 1, 1}, 3, NULL, 0, NULL },
        { (int[]){0, 0, 0}, 3, (int[]){0, 0, 0}, 1, (int[]){3} },
        { (int[]){1, 2, -3}, 3, (int[]){-3, 1, 2}, 1, (int[]){3} },
        { (int[]){1, 1, 1, 1}, 4, NULL, 0, NULL },
        { (int[]){-1, -2, -3, -4}, 4, NULL, 0, NULL },
        { (int[]){1, 2, 3, 4}, 4, NULL, 0, NULL },
        { (int[]){-105, 0, 105}, 3, (int[]){-105, 0, 105}, 1, (int[]){3} },
        { NULL, 0, NULL, 0, NULL },  // Fixed this case
        { (int[]){0, 0, 0, 0, 0}, 5, (int[]){0, 0, 0}, 1, (int[]){3} }
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        int** expected = createExpected(tests[i].expectedTriplets, tests[i].expectedSize);
        runTest(tests[i].nums, tests[i].numsSize, expected, tests[i].expectedSize, tests[i].expectedColumnSizes, i + 1);
    }

    return 0;
}
