#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int tsp(int mask, int pos, vector<vector<int>>& dp, const vector<vector<int>>& dist) {
    if (mask == (1 << dist.size()) - 1) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int ans = INF;
    for (int i = 0; i < dist.size(); i++) {
        if ((mask & (1 << i)) == 0) {
            ans = min(ans, dist[pos][i] + tsp(mask | (1 << i), i, dp, dist));
        }
    }
    dp[mask][pos] = ans;
    return ans;
}

int main() {
    vector<vector<int>> dist = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    vector<vector<int>> dp(1 << dist.size(), vector<int>(dist.size(), -1));
    cout << "The minimum cost of the TSP is " << tsp(1, 0, dp, dist) << endl;

    return 0;
}
