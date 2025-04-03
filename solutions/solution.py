class Solution:
    def threeSum(self, nums):
        result = []
        n = len(nums)
        
        if n < 3:
            return result

        nums.sort()  # Sort the array for two-pointer technique

        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:  # Skip duplicates for i
                continue
            
            left = i + 1
            right = n - 1
            target = -nums[i]

            while left < right:
                sum = nums[left] + nums[right]
                
                if sum == target:
                    result.append([nums[i], nums[left], nums[right]])
                    
                    # Skip duplicates for left and right
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    
                    left += 1
                    right -= 1
                elif sum < target:
                    left += 1
                else:
                    right -= 1
        
        return result # ..
