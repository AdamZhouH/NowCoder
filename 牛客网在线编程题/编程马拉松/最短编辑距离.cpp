#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(const string &a, const string &b);
};

int Solution::minDistance(const string &a, const string &b) {
    int m = a.size(); int n = b.size();
    if (a == "") return n;
    if (b == "") return m;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // dp数组初始化
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int i = 0; i <= n; i++) dp[0][i] = i;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[m][n];
}

int main(void) {
    Solution solu;
    string a, b;
    while (cin >> a >> b) {
        cout << solu.minDistance(a, b) << endl;
    }
    return 0;
}