#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int W = 50;
    cout << "The maximum value of items that can be carried is " << knapsack(W, wt, val) << endl;

    return 0;
}
