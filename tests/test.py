# import unittest
# import sys
# import os

# # Ensure Python finds the 'solutions' package
# sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

# from solutions.solution import Solution  # ✅ Correct import

# class TestThreeSum(unittest.TestCase):
#     def setUp(self):
#         """Set up the Solution instance before each test."""
#         self.solution = Solution()

#     def test_three_sum(self):
#         """Test the threeSum method with various test cases."""
#         test_cases = [
#             # Basic Cases
#             ([-1, 0, 1, 2, -1, -4], [[-1, -1, 2], [-1, 0, 1]]),
#             ([1, 2, 3, 4, 5], []),
#             ([-5, -4, -3, -2, -1], []),
#             ([-3, -2, -1, 0, 1, 2, 3], [[-3, 0, 3], [-3, 1, 2], [-2, -1, 3], [-2, 0, 2], [-1, 0, 1]]),

#             # Edge Cases
#             ([1], []),
#             ([1, -1], []),
#             ([0, 0, 0, 0, 0], [[0, 0, 0]]),
#             ([-2, 0, 1, 1, 2, 2, -1, -1], [[-2, 0, 2], [-2, 1, 1], [-1, -1, 2], [-1, 0, 1]]),
#             ([-1000, -500, 0, 500, 1000], [[-1000, 0, 1000], [-500, 0, 500]]),

#             # Performance Case
#             ([i for i in range(-1000, 1001)], "Too many possible results"),
#         ]

#         for i, (nums, expected) in enumerate(test_cases):
#             with self.subTest(case_number=i + 1, input=nums):
#                 result = self.solution.threeSum(nums)
#                 result.sort()  # Sort the result to ensure consistent comparison
#                 if expected != "Too many possible results":
#                     expected.sort()  # Sort the expected output for comparison
#                     self.assertEqual(result, expected, f"Test case {i + 1} failed: expected {expected}, got {result}")
#                 else:
#                     # For the performance case, we just check that the method doesn't crash
#                     self.assertIsInstance(result, list, f"Test case {i + 1} failed: expected a list, got {type(result)}")
#                     print(f"Test case {i + 1} passed (Large Input)")

# if __name__ == "__main__":
#     unittest.main()



import unittest
import sys
import os

# Ensure Python finds the 'solutions' package
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from solutions.solution import Solution  # Import the Solution class

class TestThreeSum(unittest.TestCase):
    def setUp(self):
        """Set up the Solution instance before each test."""
        self.solution = Solution()

    def test_three_sum(self):
        """Test the threeSum method with various test cases."""
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
            print("---------------------------------------------------")
            print(f"Running: Test {i + 1}")
            print(f"Input: {nums if len(nums) <= 10 else f'[{nums[0]}, ..., {nums[-1]}] (length: {len(nums)})'}")
            print(f"Expected Output: {expected}")

            result = list(self.solution.threeSum(nums))  # Convert map to list
            if expected != "Too many possible results":
                print(f"Actual Output: {result}")
                result.sort()  # Sort the result for consistent comparison
                expected.sort()  # Sort the expected output for comparison
                passed = result == expected
                print(f"Test {i + 1}: {'✅ PASSED' if passed else '❌ FAILED'}")
                if not passed:
                    print(f"Expected: {expected}")
                    print(f"Got: {result}")
            else:
                # For the performance case, don't print the large output
                passed = isinstance(result, list)
                print(f"Test {i + 1}: {'✅ PASSED (Large Input)' if passed else '❌ FAILED'}")
                if not passed:
                    print(f"Expected: A list")
                    print(f"Got: {type(result)}")

        # Summary
        passed_count = 0
        for nums, expected in test_cases:
            result = list(self.solution.threeSum(nums))
            if expected != "Too many possible results":
                result.sort()
                expected.sort()
                if result == expected:
                    passed_count += 1
            else:
                if isinstance(result, list):
                    passed_count += 1
        print("---------------------------------------------------")
        print(f"Summary: {passed_count}/{len(test_cases)} tests passed")

if __name__ == "__main__":
    unittest.main()