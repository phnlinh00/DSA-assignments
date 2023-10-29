#include <iostream>
#include <vector>
using namespace std;

int largestSum(int n, int target, vector<pair<int, int>>& objects) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= objects[i - 1].first) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - objects[i - 1].first] + objects[i - 1].second);
            }
        }
    }

    return dp[n][target];
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<pair<int, int>> objects(n);

    for (int i = 0; i < n; i++) {
        cin >> objects[i].first >> objects[i].second;
    }

    cout << largestSum(n, target, objects) << endl;

    return 0;
}
