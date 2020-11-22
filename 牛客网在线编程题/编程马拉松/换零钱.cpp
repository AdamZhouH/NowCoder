#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

// 动态规划思想-简单的背包问题
// dp[i][j] = dp[i-1][j] + dp[i][j - arr[i]] 

const int money[] = {1, 5, 10, 25, 50};

class Solution {
public:
    void findTypes();
};

void Solution::findTypes() {
    int val;
    while (cin >> val) {
        vector<vector<long long>> dp(5, vector<long long> (val + 1, 0));
        for (int i = 0; i < 5; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= val; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j <= val; j++) {
                if (j < money[i])
                    dp[i][j] = dp[i - 1][j];
                else
                	// 最开始的动态规划的改进
                    dp[i][j] = dp[i - 1][j] + dp[i][j - money[i]];
            }
        }
        cout << dp[4][val] << endl;
    }
}

int main(void) {
    Solution solu;
    solu.findTypes();
    return 0;
}