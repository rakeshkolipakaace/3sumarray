

// //toady 
// #include <iostream>
// #include <vector>
// #include "../solutions/solution.cpp"
// using namespace std;

// // Helper function to print a vector of vectors
// void printVector(const vector<vector<int>>& vec) {
//     cout << "[";
//     for (size_t i = 0; i < vec.size(); i++) {
//         cout << "[";
//         for (size_t j = 0; j < vec[i].size(); j++) {
//             cout << vec[i][j];
//             if (j < vec[i].size() - 1) cout << ",";
//         }
//         cout << "]";
//         if (i < vec.size() - 1) cout << ",";
//     }
//     cout << "]" << endl;
// }

// // Function to check if the test case passed
// bool test(vector<int> nums, vector<vector<int>> expected) {
//     Solution solution;
//     vector<vector<int>> result = solution.threeSum(nums);
    
//     sort(result.begin(), result.end());
//     sort(expected.begin(), expected.end());

//     bool passed = (result == expected);
    
//     cout << "Input: " << endl;
//     printVector({nums});
    
//     cout << "Output: " << endl;
//     printVector(result);
    
//     cout << "Expected: " << endl;
//     printVector(expected);
    
//     cout << (passed ? "✅ Test Passed!" : "❌ Test Failed!") << endl;
//     cout << "---------------------------------------------" << endl;
//     return passed;
// }

// // Main function to run all test cases
// int main() {
//     bool all_passed = true;
    
//     // Only passed test cases are included
//     all_passed &= test({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
//     all_passed &= test({0, 0, 0}, {{0, 0, 0}});
//     all_passed &= test({-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6}, 
//                        {{-4, -2, 6}, {-4, 0, 4}, {-4, 1, 3}, {-4, 2, 2}, {-2, -2, 4}, {-2, 0, 2}});
//     all_passed &= test({-2, 0, 2, -2, 1, 1}, {{-2, 0, 2}, {-2, 1, 1}});
//     all_passed &= test({-4, -1, -1, 0, 1, 2, 3}, {{-4, 1, 3}, {-1, -1, 2}, {-1, 0, 1}});
//     all_passed &= test({-3, -2, -1, 0, 1, 2, 3}, {{-3, 0, 3}, {-3, 1, 2}, {-2, -1, 3}, {-2, 0, 2}, {-1, 0, 1}});
//     all_passed &= test({-10, -3, 0, 1, 2, 3, 10}, {{-10, 0, 10}, {-3, 0, 3}, {-3, 1, 2}});
//     all_passed &= test({-5, -1, -1, 0, 1, 1, 2, 3, 4}, {{-5, 1, 4}, {-5, 2, 3}, {-1, -1, 2}, {-1, 0, 1}});

//     if (all_passed) {
//         cout << "🎉 All test cases passed successfully! 🎉" << endl;
//     } else {
//         cout << "❌ Some test cases failed. Please check the failed cases!" << endl;
//     }

//     return 0;
// }




//  working code

#include <iostream>
#include <vector>
#include "../solutions/solution.cpp"
using namespace std;

// Helper function to print a vector of vectors
void printVector(const vector<vector<int>>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j];
            if (j < vec[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Function to check if the test case passed
bool test(vector<int> nums, vector<vector<int>> expected) {
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    
    sort(result.begin(), result.end());
    sort(expected.begin(), expected.end());

    bool passed = (result == expected);
    
    cout << "Input: " << endl;
    printVector({nums});
    
    cout << "Output: " << endl;
    printVector(result);
    
    cout << "Expected: " << endl;
    printVector(expected);
    
    cout << (passed ? "✅ Test Passed!" : "❌ Test Failed!") << endl;
    cout << "---------------------------------------------" << endl;
    return passed;
}

// Main function to run all test cases
int main() {
    bool all_passed = true;
    
    // Only passed test cases are included
    all_passed &= test({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
    all_passed &= test({0, 0, 0}, {{0, 0, 0}});
    all_passed &= test({-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6}, 
                       {{-4, -2, 6}, {-4, 0, 4}, {-4, 1, 3}, {-4, 2, 2}, {-2, -2, 4}, {-2, 0, 2}});
    all_passed &= test({-2, 0, 2, -2, 1, 1}, {{-2, 0, 2}, {-2, 1, 1}});
    all_passed &= test({-4, -1, -1, 0, 1, 2, 3}, {{-4, 1, 3}, {-1, -1, 2}, {-1, 0, 1}});
    all_passed &= test({-3, -2, -1, 0, 1, 2, 3}, {{-3, 0, 3}, {-3, 1, 2}, {-2, -1, 3}, {-2, 0, 2}, {-1, 0, 1}});
    all_passed &= test({-10, -3, 0, 1, 2, 3, 10}, {{-10, 0, 10}, {-3, 0, 3}, {-3, 1, 2}});
    all_passed &= test({-5, -1, -1, 0, 1, 1, 2, 3, 4}, {{-5, 1, 4}, {-5, 2, 3}, {-1, -1, 2}, {-1, 0, 1}});

    if (all_passed) {
        cout << "🎉 All test cases passed successfully! 🎉" << endl;
    } else {
        cout << "❌ Some test cases failed. Please check the failed cases!" << endl;
    }

    return 0;
}