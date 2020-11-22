#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 很明显是hash表题目，可以选择自定义简单数组，用作hash表，一可以直接选择set
// 前置可能由于n比较大，导致空间复杂度比较大，但是每次查询的时间为常数
// 选择set则时间复杂度高一些，但是省空间

class Solution {
public:
	void findNotin(void) {
		set<int> values;
		int n; cin >> n;
		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			values.insert(temp);
		}
		// 遍历，寻找不存在的元素
		for (int i = 0; i <= n; i++) {
			if (values.find(i) == values.end()) {
				cout << i << endl;
				return;
			}
		}
	}
};

int main(void) {
	Solution solu;
	while (cin) {
		solu.findNotin();
	}
	return 0;
} 