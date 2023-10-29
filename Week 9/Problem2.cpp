#include <iostream>
#include <vector>
using namespace std;

bool canFormGroup(int n, int target, vector<int>& ages) {
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (ages[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - ages[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> ages(n);

    for (auto &it : ages) {
        cin >> it;
    }

    if (canFormGroup(n, target, ages)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
