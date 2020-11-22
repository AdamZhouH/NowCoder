#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
	void arrangeWork(vector<pair<int, int>> &works, vector<pair<int, int>> &persons, int n, int m);
};

void Solution::arrangeWork(vector<pair<int, int>> &works, vector<pair<int, int>> &persons, int n, int m) {
	vector<pair<int, int>> reward(m);
	// 给定工作任务按难度的非降序排列
	sort(works.begin(), works.end(), [] (const pair<int, int> &a, const pair<int, int> &b) {
		return a.first < b.first;
	});
	// 成员能力按照非降序排列
	sort(persons.begin(), persons.end(), [] (const pair<int, int> &a, const pair<int, int> &b) {
		return a.first < b.first;
	});
	// 更新works中的pair的second成员为first工作难度下，能够获得的最大报酬
	int maxReward = 0;
	for (int i = 0; i < n; i++) {
		maxReward = max(maxReward, works[i].second);
		works[i].second = maxReward;
	}
	// 对于每个人，按照能力去匹配能够获得最大收益的work，并记录其收益
	for (int i = 0, j = 0; i < m; i++) {
		while (j < n && works[j].first <= persons[i].first ) j++;
		reward[i].first = persons[i].second;
		reward[i].second = works[j - 1].second;
	}
	// 把reward按照成员加入的顺序重排并输出
	sort(reward.begin(), reward.end(), [] (const pair<int, int> &a, const pair<int, int> &b) {
		return a.first < b.first;
	});
	for (int i = 0; i < m; i++)
		cout << reward[i].second << endl;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> works(n), persons(m);
	int di, pi, ai;
	for (int i = 0; i < n; i++) {
		cin >> di >> pi;
		works[i].first = di;
		works[i].second = pi;
	}
	for (int i = 0; i < m; i++) {
		cin >> ai;
		persons[i].first = ai;
		persons[i].second = i;
	}

	Solution solution;
	solution.arrangeWork(works, persons, n, m);
	return 0;
}