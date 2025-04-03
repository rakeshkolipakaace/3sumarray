def test_three_sum():
    solution = Solution()

    test_cases = [
        # Basic Cases
        ([-1, 0, 1, 2, -1, -4], [[-1, -1, 2], [-1, 0, 1]]),
        ([1, 2, 3, 4, 5], []),
        ([-5, -4, -3, -2, -1], []),
        ([-3, -2, -1, 0, 1, 2, 3], [[-3, 0, 3], [-3, 1, 2], [-2, -1, 3], [-2, 0, 2], [-1, 0, 1]]),

        # Edge Cases
        ([1], []),
        ([1, -1], []),
        ([0, 0, 0, 0, 0], [[0, 0, 0]]),
        ([-2, 0, 1, 1, 2, 2, -1, -1], [[-2, 0, 2], [-2, 1, 1], [-1, -1, 2], [-1, 0, 1]]),
        ([-1000, -500, 0, 500, 1000], [[-1000, 0, 1000], [-500, 0, 500]]),

        # Performance Case
        ([i for i in range(-1000, 1001)], "Too many possible results"),
    ]

    for i, (nums, expected) in enumerate(test_cases):
        result = solution.threeSum(nums)
        # Sorting lists to compare without worrying about order
        result.sort()
        if expected != "Too many possible results":
            expected.sort()
            assert result == expected, f"Test {i + 1} failed: expected {expected}, got {result}"
        else:
            print(f"Test {i + 1} passed (Large Input)")

    print("All test cases passed!")

# Run tests
test_three_sum()
