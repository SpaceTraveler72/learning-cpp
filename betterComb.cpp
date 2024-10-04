#include <iostream>
#include <vector>
using namespace std;

void combinationSumFastRecursion(const vector<int>& nums, int target, int sum, int& result) {
    // Increase result if sum is equal to target
    if (sum == target) {
        result++;
        return;
    } 
    // Return if sum is too large
    if (sum > target) return;

    // Check through all possible combinations of nums
    for (int num : nums) {
        combinationSumFastRecursion(nums, target, sum + num, result);
    }
}

int combinationSum4Fast(const vector<int>& nums, int target) {
    int totalCombinations = 0;
    combinationSumFastRecursion(nums, target, 0, totalCombinations);
    return totalCombinations;
}

void printTotalCombinations(int totalCombinations) {
    cout << "Total Combinations: " << totalCombinations << endl;
}

int main() {
    int target = 30;
    vector<int> nums = { 1, 2, 4, 7 };

    int totalCombinations = combinationSum4Fast(nums, target);
    printTotalCombinations(totalCombinations);
}