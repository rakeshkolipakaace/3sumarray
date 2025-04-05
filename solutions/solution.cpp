#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 3) return result;

        // Sort the array to handle duplicates and use two-pointer technique
        sort(nums.begin(), nums.end());

        // Iterate through the array
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Add the triplet to the result
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move pointers to next unique elements
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++;  // Increase sum by moving left pointer
                } 
                else {
                    right--;  // Decrease sum by moving right pointer
                }
            }
        }
        
        return result;
    }// solution ....
};