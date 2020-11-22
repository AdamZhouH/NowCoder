// 剑指offer题目，求最大利润

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
	int maxProfit(void);
};

int Solution::maxProfit(void) {
	int val;
	vector<int> price;
	while (scanf("%d", &val) != EOF) {
		price.push_back(val);
	}
	
	// 使用遍历算法，每次迭代，记录当前的最小值
	int maxP = INT_MIN;
	int currmin = price[0];

	for (int i = 1; i < price.size(); i++) {
		currmin = min(currmin, price[i]);
		maxP = max(price[i] - currmin, maxP);
	}
	return maxP;
}

int main(void) {
	Solution solu;
	cout << solu.maxProfit() << endl;
	return 0;
}