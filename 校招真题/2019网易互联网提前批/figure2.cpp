#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <new>
#include <stack>
#include <deque>
#include <queue>
#include <utility>
#include <memory>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
using namespace std;

    // 利用优先队列排序
struct large {
	bool operator ()(const pair<int, int> &a, const pair<int, int> &b) {
		return a.second > b.second;
	}
};
	
struct small {
	bool operator ()(const pair<int, int> &a, const pair<int, int> &b) {
		return a.second < b.second;
	}
};

int main(void) {
	// 数据输入
	int n, k;
	cin >> n >> k;
	int var;

	priority_queue<pair<int, int>, vector<pair<int, int>>, small> bigHeap;   // 大堆
	priority_queue<pair<int, int>, vector<pair<int, int>>, large> smallHeap; // 小堆

	for (int i = 0; i < n; i++) {
		cin >> var;
		bigHeap.push(make_pair(i, var));
		smallHeap.push(make_pair(i, var));
	}

//	assert(bigHeap.top().first >= smallHeap.top().first);
//	cout << bigHeap.top().first << ' ' << smallHeap.top().first << endl;

	vector<pair<int, int>> result;

	for (int i = 0; i < k; i++) {
		auto small = smallHeap.top();
		auto big = bigHeap.top();
		if ((big.second - small.second) > 1) {
			smallHeap.pop();
			bigHeap.pop();
//			cout << big.second << ' ' << small.second << endl;
			smallHeap.push(make_pair(small.first, ++(small.second)));
			bigHeap.push(make_pair(big.first, --(big.second)));

			result.push_back(make_pair(big.first, small.first));
		} else
			break;
	}
	cout << (bigHeap.top().second - smallHeap.top().second) << ' ' << result.size() << endl;
	
	for (int i = 0; i < result.size(); i++) {
		cout << result[i].first << ' ' << result[i].second << endl;
	}

	return 0;
}