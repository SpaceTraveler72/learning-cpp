#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return sum;
}

void combinationSumRecursion(vector<int> nums, vector<int> current, vector<vector<int>>& result, int target) {
    // add current to result if sum of current is equal to target
    if (sum(current) == target) {
        result.push_back(current);
        return;
    }
    // return if sum of current is too large
    if (sum(current) > target) return;

    // checks through all possible combinations of nums
    for (int i = 0; i < nums.size(); i++) {
        current.push_back(nums[i]);
        combinationSumRecursion(nums, current, result, target);
        // shrinks current to check other combinations
        current.pop_back();
    }
}

void combinationSumFastRecursion(vector<int> nums, int target, int sum, int& result) {
    // add current to result if sum of current is equal to target
    if (sum == target) {
        result++;
        return;
    }
    // return if sum of current is too large
    if (sum > target) return;

    // checks through all possible combinations of nums
    for (int num : nums) {
        combinationSumFastRecursion(nums, target, sum + num, result);
    }
}

vector<vector<int>> combinationSum4(vector<int> nums, int target) {
    vector<vector<int>> result;
    int totalCombinations = 0;

    combinationSumRecursion(nums, {}, result, target);
    combinationSumFastRecursion(nums, target, 0, totalCombinations);
    result.push_back({totalCombinations});
    
    return result;
}

int combinationSum4Fast(vector<int> nums, int target) {
    int totalCombinations = 0;
    combinationSumFastRecursion(nums, target, 0, totalCombinations);
    return totalCombinations;
}

void printSolution(vector<vector<int>> result) {
    for (int i = 0; i < result.size() - 1; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Total Combinations: " << result[result.size() - 1][0] << endl;
}

void printTotalCombinations(int totalCombinations) {

    cout << "Total Combinations: " << totalCombinations << endl;
}

int main() {
    int target = 19;
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printSolution(combinationSum4(nums, target));
    //printTotalCombinations(combinationSum4Fast(nums, target));

}