package solutions;

import java.util.*;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        
        // Sort the array to simplify finding duplicates and finding triplets
        Arrays.sort(nums);
        
        // Iterate over the array
        for (int i = 0; i < nums.length - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Two-pointer approach to find pairs that sum to the negative of the current element
            int left = i + 1;
            int right = nums.length - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move pointers after finding a valid triplet
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;  // We need a larger sum, so move the left pointer to the right
                } else {
                    right--; // We need a smaller sum, so move the right pointer to the left....
                }
            }
        }
        
        return result;
    }
}
