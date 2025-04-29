#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting the array
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    // Initialize result and column sizes
    int** result = (int**)malloc(sizeof(int*) * 1000); // Initial assumption of max 1000 triplets
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000); // For storing sizes of each result triplet
    *returnSize = 0; // To track the number of triplets found

    // Iterate through the array to find triplets
    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicates for the first number in the triplet
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        // Two-pointer approach for the second and third numbers
        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                // Found a triplet, allocate memory for it and store it
                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3; // The size of each triplet is 3
                (*returnSize)++;

                // Skip duplicates for the second and third numbers
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                // Move both pointers to look for other pairs
                left++;
                right--;
            } else if (sum < 0) {
                left++;  // We need a larger sum, move the left pointer to the right
            } else {
                right--; // We need a smaller sum, move the right pointer to the left..
            }
        }
    }

    return result;
}