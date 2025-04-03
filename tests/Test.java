package tests;  // ✅ Added package declaration

import solutions.Solution;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Test {
    static class ThreeSumTest {
        private Solution solution = new Solution();  // ✅ Fixed class name capitalization

        private boolean listsEqual(List<List<Integer>> expected, List<List<Integer>> actual) {
            if (expected.size() != actual.size()) return false;
            return expected.containsAll(actual) && actual.containsAll(expected);
        }

        private void runTest(String testName, int[] nums, List<List<Integer>> expected) {
            List<List<Integer>> result = solution.threeSum(nums);
            boolean passed = listsEqual(expected, result);
            System.out.println(testName + ": " + (passed ? "✅ PASSED" : "❌ FAILED"));
            if (!passed) {
                System.out.println("Expected: " + expected);
                System.out.println("Got: " + result);
            }
        }

        public void runAllTests() {
            runTest("Test 1", new int[]{-1, 0, 1, 2, -1, -4}, 
                    Arrays.asList(Arrays.asList(-1, -1, 2), Arrays.asList(-1, 0, 1)));

            runTest("Test 2", new int[]{0, 1, 1}, new ArrayList<>());

            runTest("Test 3", new int[]{0, 0, 0}, 
                    Arrays.asList(Arrays.asList(0, 0, 0)));

            runTest("Test 4", new int[]{1, 2, -3}, 
                    Arrays.asList(Arrays.asList(-3, 1, 2)));

            runTest("Test 5", new int[]{1, 1, 1, 1}, new ArrayList<>());

            runTest("Test 6", new int[]{-1, -2, -3, -4}, new ArrayList<>());

            runTest("Test 7", new int[]{1, 2, 3, 4}, new ArrayList<>());

            runTest("Test 8", new int[]{-105, 0, 105}, 
                    Arrays.asList(Arrays.asList(-105, 0, 105)));

            runTest("Test 9", new int[]{}, new ArrayList<>());

            runTest("Test 10", null, new ArrayList<>());

            runTest("Test 11", new int[]{0, 0, 0, 0, 0}, 
                    Arrays.asList(Arrays.asList(0, 0, 0)));
        }
    }

    public static void main(String[] args) {
        ThreeSumTest tester = new ThreeSumTest();
        tester.runAllTests();
    }
}
