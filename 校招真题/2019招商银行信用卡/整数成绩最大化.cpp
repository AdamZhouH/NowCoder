#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 将一个整数n分解为至少两个整数之和，使得这些整数的乘积最大
// 思路
// 考虑递归和动态规划的思路
// 针对一个整数，先分解为两个整数的和，那么这两个整数可以继续分解，也可不分解
// 对于两个整数，四种情况，都不分解（意思是原数仅仅分解为这两个整数），
// 两个都分解，分解其中一个（这是两种情况）
// 并且分成两个数之和的情况有之多n/2中
// 因此可以给出递归公式，使用动态规划的方法去做
// f(n) = max{f(1) * f(n-1), f(2) * f(n - 2), ...f(n/2) * f(n - n / 2)}

class Solution {
public:
	int maxMulti(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 0;
		if (n == 2)
			return 1;

		vector<int> dp(n + 1, 0);
		dp[0] = dp[1] = 0;
		dp[2] = 1;
		for (int i = 3; i <= n; i++) {
			int currMax = 0;
			for (int j = 1; j <= i / 2; j++) {
				currMax = max(currMax, 
							  max(max(j * (i - j), dp[j] * dp[i - j]), 
							  	  max(j * dp[i - j], dp[j] * (i - j))));
			}
			dp[i] = currMax;
		}
		return dp[n];
	}
};

int main(void) {
	Solution solu;
	int val;
	while (cin >> val) {
		cout << solu.maxMulti(val) << endl;
	}
	return 0;
}