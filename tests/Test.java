package tests;

import solutions.solution;  // ✅ Importing lowercase "solution"

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Test {
    private static solution solution = new solution();  // ✅ Use lowercase class name

    private static boolean listsEqual(List<List<Integer>> expected, List<List<Integer>> actual) {
        if (expected.size() != actual.size()) return false;
        return expected.containsAll(actual) && actual.containsAll(expected);
    }

    private static void runTest(String testName, int[] nums, List<List<Integer>> expected) {
        System.out.println("---------------------------------------------------");
        System.out.println("Running: " + testName);
        System.out.println("Input: " + Arrays.toString(nums));

        List<List<Integer>> result = solution.threeSum(nums);
        boolean passed = listsEqual(expected, result);

        System.out.println("Expected Output: " + expected);
        System.out.println("Actual Output  : " + result);
        System.out.println(testName + ": " + (passed ? "✅ PASSED" : "❌ FAILED"));
        System.out.println("---------------------------------------------------\n");
    }

    public static void main(String[] args) {
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
