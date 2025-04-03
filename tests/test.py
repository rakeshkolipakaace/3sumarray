def test_cases():
    return [
        # ✅ Basic Test Cases
        ([-1, 0, 1, 2, -1, -4], [[-1, -1, 2], [-1, 0, 1]]),  # Standard case
        ([0, 1, 1], []),  # No triplet sums to zero
        ([0, 0, 0], [[0, 0, 0]]),  # All zeros
        
        # ✅ Edge Cases
        ([1], []),  # Single element
        ([1, 2], []),  # Only two elements
        ([], []),  # Empty array
        ([-4, -1, -1, 0, 1, 2], [[-4, 1, 2], [-1, -1, 2], [-1, 0, 1]]),  # Mixed negatives and positives
        ([-5, -3, -1, -2, -4], []),  # All negative numbers
        ([1, 2, 3, 4, 5], []),  # All positive numbers
        
        # ✅ Cases with Duplicates
        ([-2, 0, 2, -2, 1, 1], [[-2, 0, 2], [-2, 1, 1]]),  # Handling duplicates
        ([0, 0, 0, 0, 0, 0], [[0, 0, 0]]),  # Multiple zeros
        ([-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6],  
         [[-4, -2, 6], [-4, 0, 4], [-4, 1, 3], [-4, 2, 2], [-2, -2, 4], [-2, 0, 2]]),  # Large input with duplicates
        
        # ✅ Large Numbers
        ([10**5, -10**5, 0], [[-100000, 0, 100000]]),  # Large positive and negative numbers
        ([10**6, -10**6, 0, 0, 0], [[-1000000, 0, 1000000], [0, 0, 0]]),  # Large numbers with multiple zeros
        
        # ✅ Large Input Size
        ([-1] * 500 + [0] * 500 + [1] * 500, [[-1, 0, 1]]),  # Large input with duplicates
    ]
