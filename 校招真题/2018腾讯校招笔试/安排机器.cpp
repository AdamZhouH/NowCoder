#include <iostream>
#include <algorithm>
using namespace std;

const int DIFFICULTY_LIMIT = 101;
const int LEVEL_LIMIT = 101;

struct Node {
		int x;
		int y;
};

bool compare(const Node &lhs, const Node &rhs) {
	if (lhs.x == rhs.x)
			return lhs.y >= rhs.y;
		return lhs.x >= rhs.x;
}

class Solution {
public:
	void solution();
};

void Solution::solution() {
	// 处理数据输入
	int n, m, xi, yi, zi, wi;
	int count = 0, profit = 0;
	cin >> n >> m;
	Node *machiens = new Node[n];
	Node *tasks = new Node[m];
	int *counts = new int[LEVEL_LIMIT] {0};

	for (int i = 0; i < n; i++)
		cin >> machiens[i].x >> machiens[i].y;
 	for (int i = 0; i < m; i++)
		cin >> tasks[i].x >> tasks[i].y;

	// 任务和机器都按照时间和难度等级排序，这里采用时间优先，时间相同则比较难度
	sort(machiens, machiens + n, compare);
	sort(tasks, tasks + m, compare);

	// 算法思路，题目首先要求能够完成的任务数量最大，考虑贪心思路能否完成相应的安排
	// 设置一个数组，数组下标表示机器的等级，对应的值表示可以完成不大于此等级的任务的机器数量
	// 遍历每一个任务，并针对每一个任务，找到时间上可以满足此任务的所有机器
	// 然后针对此任务，找到一个难度值恰好能够满足的机器使用

	// 注意，时间上因为，任务和机器都是按照时间降序排列，第一个任务的时间都可以满足，那么可以保证目前标记的机器都是
	// 可以满足下一个任务的

	int i, j, k;
	for (int i = 0, j = 0; i < m; i++) {
		while (j < n && machiens[j].x >= tasks[i].x) {
			counts[machiens[j].y]++;
			j++;
		}
		// 针对当前任务i，找到最合适的机器第一个可以满足难度值的机器）
		for (k = tasks[i].y; k < LEVEL_LIMIT; k++) {
			if (counts[k]) {
				count++;
				counts[k]--;   // 已经使用了一台机器了
				profit += 200 * tasks[i].x + 3 * tasks[i].y;
				break;   // 已经找到任务的最佳机器，不用再寻找
			}
		}
	}
	delete [] tasks;
	delete [] machiens;
	delete [] counts;

	cout << count << ' ' << profit << endl;
}

int main(void) {
	Solution s;
	s.solution();
	return 0;
}

// 着一道题目的核心思路就是贪心思路，其中的贪心有
// 1.任务数量的贪心，那么需要每次选择时间和难度都恰好满足的机器，才能让任务数量最多
// 2.收益值的贪心，由于时间占受益值的绝大部分，因此优先考虑时间，计算收益从满足时间最多的任务开始
