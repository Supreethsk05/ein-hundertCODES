#include <iostream>
#include <vector>
using namespace std;

int maxCoins(vector<int>& nums) {
    // Add boundary balloons with value 1
    int n = nums.size();
    vector<int> balloons(n + 2);
    balloons[0] = balloons[n + 1] = 1;
    for (int i = 0; i < n; i++) {
        balloons[i + 1] = nums[i];
    }

    // dp[i][j] represents the maximum number of coins that can be obtained
    // by bursting all the balloons between i and j (excluding i and j)
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + balloons[i - 1] * balloons[k] * balloons[j + 1] + dp[k + 1][j]);
            }
        }
    }

    return dp[1][n];
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    cout << "The maximum number of coins that can be obtained is " << maxCoins(nums) << endl;

    return 0;
}
