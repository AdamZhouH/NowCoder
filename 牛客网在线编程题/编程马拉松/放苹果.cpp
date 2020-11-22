#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long methods(int m, int n);
};

long long Solution::methods(int m, int n) {
    vector<vector<long long>> dp(m + 1, vector<long long> (n + 1, 0));
    // 利用动态规划，dp[i][j] i个苹果放到j个盘子里面
    // 只有一个盘子的情况 
    for (int i = 0; i <= m; i++)
    	dp[i][1] = 1;
    // 没有苹果的情况
    for (int i = 0; i <= n; i++)
    	dp[0][i] = 1;
    // 要判断篮子数目和苹果数目的关系
    // 这里篮子数目最好不要用从0开始的下标，因为和苹果数目最好是对应的
    // 不然编码比较复杂，而且不易于理解
    for (int i = 1; i <= m; i++) {
    	for (int j = 1; j <= n; j++) {
    		if (i < j) 
    			dp[i][j] = dp[i][i];
    		else
    			dp[i][j] = dp[i - j][j] + dp[i][j - 1];
    	}
    }
    return dp[m][n];
}

int main(void) {
    int m, n;
    Solution solu;
    while (cin >> m >> n) {
        cout << solu.methods(m, n) << endl;
    }
    return 0;
}