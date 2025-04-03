#include <iostream>
#include <vector>
#include "../solutions/solution.cpp"
using namespace std;

void printResult(const vector<vector<int>>& results) {
    cout << "[";
    for (size_t i = 0; i < results.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < results[i].size(); j++) {
            cout << results[i][j];
            if (j < results[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < results.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    vector<vector<int>> test_cases = {
        {-1, 0, 1, 2, -1, -4},  // Expected: [[-1, -1, 2], [-1, 0, 1]]
        {0, 1, 1},              // Expected: []
        {0, 0, 0},              // Expected: [[0, 0, 0]]
        {-3, -2, -1, 0, 1, 2, 3},  // Expected: [[-3, 0, 3], [-3, 1, 2], [-2, -1, 3], [-2, 0, 2], [-1, 0, 1]]
        {1},                    // Edge Case: Expected []
        {1, -1},                // Edge Case: Expected []
        {-1000, -500, 0, 500, 1000},  // Expected: [[-1000, 0, 1000], [-500, 0, 500]]
        {-2, 0, 1, 1, 2, 2, -1, -1}, // Expected: [[-2, 0, 2], [-2, 1, 1], [-1, -1, 2], [-1, 0, 1]]
        {100, 200, -300, 1, -1, 2, -2}, // Expected: [[-300, 100, 200], [-2, 0, 2], [-1, 0, 1]]
    };

    for (const auto& test_case : test_cases) {
        vector<int> nums = test_case;
        vector<vector<int>> result = solution.threeSum(nums);
        cout << "Input: ";
        printResult({test_case});
        cout << "Output: ";
        printResult(result);
        cout << "--------------------------------------\n";
    }

    return 0;
}
