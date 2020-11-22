#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 思路
// 把()分别堪称01
// 合法的序列则是，从左往右遍历整个序列，保证0的个数一直不小于1的个数一直到最后
// 否则不合法
// 因此，问题转换为求合法的01序列，长度为n/2
// 考虑dfs遍历
// dfs遍历的基本思想，先取当前一个字符为(或者)，然后dfs取后面的序列
// 考虑当前取哪一个字符的判断标准，首先，必须记录当前，(和)分别的个数
// 如果(多于)，则两者都可以取，因此分别dfs这两种情况
// 如果不多于，并且此时的(的个数还没到达n，那么只能放(，才能保证合法的序列
// 综上，可以给出解法

// 顺便复习dfs的核心思想，就是递归分治的思想，然后写成递归代码
// 考虑全排列也可以这种写法，不过全排列需要回溯，因此当递归返时，需要恢复之前的状态

class Solution {
public:
	vector<string> findValid(int n);
	void dfs(vector<string> &ret, string curr, int l, int r, int x, int n);
};

vector<string> Solution::findValid(int n) {
	vector<string> ret;
	dfs(ret, "", 0, 0, 0, n);
	return ret;
}

void Solution::dfs(vector<string> &ret, string curr, int l, int r, int x, int n) {
	if (x == 2 * n) {
		ret.push_back(curr);
		return;
	}
	// 如果当前(的个数还没有到达n
	if (l < n)
		dfs(ret, curr + "(", l + 1, r, x + 1, n);
	// 如果当前)的个数还没有到达n，并且少于(
	if (r < n && l > r)
		dfs(ret, curr + ")", l, r + 1, x + 1, n);
}

int main(void) {
	Solution solu;
	int n;
	while (cin >> n) {
		auto ret = solu.findValid(n);
		for (int i = 0; i < ret.size(); i++) {
			if (i != ret.size() - 1)
				cout << ret[i] << ',';
			else
				cout << ret[i] << endl;
		}	
	}
	return 0;
}