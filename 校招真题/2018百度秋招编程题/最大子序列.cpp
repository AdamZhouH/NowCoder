#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Solution {
public:
	string findMaxSub(const string &str);
};

string Solution::findMaxSub(const string &str) {
	if (str.empty() || str.size() <= 1)
		return str;
	vector<int> dp(str.size());
	vector<int> idx(str.size(), -1);
	dp[0] = 1;       // -1表示没有前驱节点了
	int maxLen = dp[0], maxIdx = 0;
	// 开始动态规划遍历寻找递增子序列的最大长度
	for (int i = 1; i < str.size(); i++) {
		dp[i] = 1;
		int prev = -1;
		for (int j = 0; j < i; j++) {
			if (str[j] <= str[i]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					prev = j;
				}
			//	dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		idx[i] = prev;         // 更新前驱
		if (maxLen < dp[i]) {
			maxLen = dp[i];
			maxIdx = i;
		}
	}
	// 从索引i处，往前遍历回去
	/** 此方法有错误，不能直接往前回溯，比如ecdfecm，最长处为m，但是u不能直接往回走，因为ec都比m小，但是不能
	    直接选择m，因此，考虑在之前的遍历过程中，记录上一个节点的位置，从而方便最后回溯回去
	deque<char> ret;
	ret.push_front(str[maxIdx]);
	int prev = maxIdx;
	int curr = maxIdx - 1;
	for (; curr >= 0;) {
		if (str[curr] <= str[prev]) {
			ret.push_front(str[curr]);
			prev = curr;
			curr--;
		} else {
			curr--;
		}
	}
	*/
	deque<int> ret;
	int curr = maxIdx;
	while (idx[curr] != -1) {
		ret.push_front(str[curr]);
		curr = idx[curr];
	}
	ret.push_front(str[curr]);
	return string(ret.begin(), ret.end());
}

int main(void) {
	string s;
	Solution solu;
	cin >> s;
	cout << solu.findMaxSub(s) << endl;
	return 0;
}