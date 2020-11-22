#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

// 考虑用bfs找最短路径的做法，类似于单源最短路径求解
// 每次遍历一点，把从当前点，一步可达达的点的距离都更新，如果可达点距离更新了
// 则把他们入队，最终迭代直到队为空
// 考虑当前点一步可达，有几种情况，前进一步，后退一步，当前点*2的点
// 每种情况如果点合法，并且最短距离可以更新，则把此点入队

class Solution {
public:
	int minStep(int n);
};

int Solution::minStep(int n) {

	if (n < 0)
		n = (-1) * n;

	vector<int> distance(n+1, INT_MAX);
	distance[0] = 0;
	queue<int> q; q.push(0);

	while (!q.empty()) {
		int idx = q.front();
		q.pop();

		if (idx + 1 <= n) {
			if (distance[idx + 1] > distance[idx] + 1) {
				distance[idx + 1] = distance[idx] + 1;
				q.push(idx + 1);
			}
		}

		if (idx * 2 <= n) {
			if (distance[idx * 2] > distance[idx] + 1) {
				distance[idx * 2] = distance[idx] + 1;
				q.push(idx * 2);
			}
		}
		if (idx - 1 >= 0) {
			if (distance[idx - 1] > distance[idx] + 1) {
				distance[idx - 1] = distance[idx] + 1;
				q.push(idx - 1);
			}
		}
	}
	return distance[n];
}

int main(void) {
	Solution solu;
	int pos;
	while (cin >> pos) {
		cout << solu.minStep(pos) << endl;
	}
	return 0;
}