#include <vector>
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
        int n = nums.size();
        
        // If array has less than 3 elements, no solution possible
        if (n < 3) return result;
        
        // Sort the array to use two-pointer technique and handle duplicates
        sort(nums.begin(), nums.end());
        
        // Iterate through array, fixing first number
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // Use two pointers for remaining two numbers
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];  // We need two numbers that sum to -nums[i]
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;  // Need larger sum, move left pointer right
                }
                else {
                    right--;  // Need smaller sum, move right pointer left
                }
            }
        }
        
        return result;
            
        }
    };