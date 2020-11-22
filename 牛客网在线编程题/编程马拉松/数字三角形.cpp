// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 牛客网输入非常坑跌，要改成循环输入，醉了...

class Solution {
public:
    void inputData();
    int getMaxSum();
private:
    vector<vector<int>> data;
    int n;
};

void Solution::inputData() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        data.push_back(vector<int>());
        int val;
        for (int j = 0; j <= i; j++) {
           cin >> val;
           data[i].push_back(val);
       }
    }
}

int Solution::getMaxSum() {
	// 二维dp数组
	// dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + data[i][j]
	vector<vector<int>> dp(n, vector<int> ());
	dp[0].push_back(data[0][0]);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i].push_back(dp[i - 1][j] + data[i][j]);
			else
				dp[i].push_back(max(dp[i - 1][j], dp[i - 1][j - 1]) + data[i][j]);
		}
	}
	int maxSum = 0;
	for (int i = 0; i < n; i++)
		maxSum = max(maxSum, dp[n - 1][i]);
	return maxSum;
}

int main(void) {
	Solution solu;
	solu.inputData();
	cout << solu.getMaxSum() << endl;
	return 0;
}