#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 3) return result;

        sort(nums.begin(), nums.end());  // Sort to handle duplicates easily and use two pointers

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates for i
            
            // Use hash map to find two numbers summing to -nums[i]
            unordered_map<int, int> seen;
            int target = -nums[i];
            
            for (int j = i + 1; j < n; j++) {
                int complement = target - nums[j];
                
                if (seen.count(complement)) {
                    result.push_back({nums[i], complement, nums[j]});
                    cout << "Found: " << nums[i] << "," << complement << "," << nums[j] << endl;
                    
                    // Skip duplicates for nums[j]
                    while (j + 1 < n && nums[j] == nums[j + 1]) j++;
                }
                seen[nums[j]] = j;
            }
        }
        return result;
    }
};