#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	int collectionNumber(void);
	void dfs(vector<int> &numbers, int idx, int sum, set<set<int>> &ret, set<int> curr);
};

void Solution::dfs(vector<int> &numbers, int idx, int sum, set<set<int>> &ret, set<int> curr) {
	if (sum == 24) {
		ret.insert(curr);
		return;
	}
	if (idx == numbers.size())
		return;
	dfs(numbers, idx + 1, sum, ret, curr);
	curr.insert(numbers[idx]);
	dfs(numbers, idx + 1, sum + numbers[idx], ret, curr);
}

int Solution::collectionNumber(void) {
	set<set<int>> ret;
	set<int> s;
	vector<int> numbers;
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		numbers.push_back(temp);
	}
	dfs(numbers, 0, 0, ret, s);
	return ret.size();
}

int main(void) {
	Solution solu;
	cout << solu.collectionNumber() << endl;
	return 0;
}