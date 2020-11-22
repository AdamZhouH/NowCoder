#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
	void adjuest(void);
};

void Solution::adjuest(void) {
	string s;
	cin >> s;
	int len = s.size();
	// 统计鸡和鸭子在原字符串中的下标
	vector<int> cindex;
	vector<int> dindex;

	for (int i = 0; i < len; i++) {
		if (s[i] == 'C')
			cindex.push_back(i);
		else
			dindex.push_back(i);
	}

	sort(cindex.begin(), cindex.end());
	sort(dindex.begin(), dindex.end());
	int count = 0;

	if (cindex.empty() || dindex.empty()) {
		cout << 0 << endl;
		return;
	}
	// 四种情况各考虑一边拉到，鸡左，鸡右，鸭左，鸭右
	int cond1 = 0, cond2 = 0, cond3 = 0, cond4 = 0;

	for (int i = 0; i < cindex.size(); i++)
		cond1 += cindex[i] - i;
	for (int i = 0; i < dindex.size(); i++)
		cond2 += dindex[i] - i;
	for (int i = cindex.size() - 1, j = len - 1; i >= 0; i--, j--)
		cond3 += j - cindex[i];
	for (int i = dindex.size() - 1, j = len - 1; i >= 0; i--, j--)
		cond4 += j - dindex[i];

	cout << (min(min(cond1, cond2), min(cond3, cond4))) << endl;
}

int main() {
	Solution solu;
	string str;
	solu.adjuest();
	return 0;
}