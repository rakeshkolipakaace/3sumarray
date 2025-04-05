package solutions;

import java.util.*;

public class Solution {  
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> result = new HashSet<>();
        int n = nums.length;
        
        for (int i = 0; i < n - 2; i++) {
            Set<Integer> seen = new HashSet<>();
            for (int j = i + 1; j < n; j++) {
                int complement = -nums[i] - nums[j];
                if (seen.contains(complement)) {
                    List<Integer> triplet = Arrays.asList(nums[i], nums[j], complement);
                    triplet.sort(null); // Sort to ensure uniqueness
                    result.add(triplet);
                }
                seen.add(nums[j]);
            }
        }
        return new ArrayList<>(result);
        
        // write your code here..
       
    }
}