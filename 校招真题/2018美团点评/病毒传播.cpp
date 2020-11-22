#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
	Solution() { readData(); }
	void findOrigin();
	void readData();
	void bfs(int node);
private:
	map<int, list<int>> graph;
	set<int> final;
	set<int> result;
	int m;
	int n;
	int t;
	int k;
};

void Solution::readData() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		auto ret = graph.find(a);
		if (ret != graph.end())
			graph[a].push_back(b);
		else
			graph[a] = {b};
	}
	cin >> k >> t;
	for (int i = 0; i < k; i++) {
		int val;
		cin >> val;
		final.insert(val);
	}
}

void Solution::bfs(int node) {
	vector<int> visited(n, 0);  // 标记是否访问过节点
	int count = t;              // 天数
	set<int> compareSet;        // 以node为起始点，t天之后的传播结果

	compareSet.insert(node);

	queue<int> q;              // BFS辅助队列
	q.push(node);

	int preNum = 1;            // 当天需要访问的节点个数
	int currNum = 0;           // 下一天需要访问的节点的个数

	while (count--) {
		while (preNum--) {
			if (q.empty())     // 需要判断队列是否为空
				break;
			int curr = q.front();
			visited[curr] = 1;       // 标记已经访问
			q.pop();

			auto lst = graph[curr];
			for (auto val : lst) {
				if (!visited[val]) {
					currNum++;
					q.push(val);
				}
			}
		}
		preNum = currNum;
		currNum = 0;
	}

	if (compareSet == final)
		result.insert(node);
}

void Solution::findOrigin() {
	for (int i = 0; i < n; i++)
		bfs(i);
	if (result.empty()) {
		cout << -1;
	} else {
		vector<int> tmp(result.begin(), result.end());
		for (int i = 0; i < tmp.size(); i++)
			if (i != tmp.size() - 1)
				cout << tmp[i] << ' ';
			else
				cout << tmp[i];
	}
}

int main(void) {
	Solution solu;
	solu.findOrigin();
	return 0;
}