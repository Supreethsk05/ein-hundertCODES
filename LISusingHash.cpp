#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> dp;

    for (int num : nums) {
        int length = 1;
        for (int j = num - 1; dp.count(j); j--) {
            length = max(length, dp[j] + 1);
        }
        dp[num] = length;
    }

    int max_length = 0;
    for (auto it : dp) {
        max_length = max(max_length, it.second);
    }
    return max_length;
}
int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "The length of the longest increasing subsequence is " << lengthOfLIS(nums) << endl;

    return 0;
}