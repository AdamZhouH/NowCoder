#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void readGrade(int n, vector<int> &grade) {
		int val;
		while (n--) {
			cin >> val;
			grade.push_back(val);
		}
	}

	int highestGrade(int from, int to, const vector<int> &grade) {
		if (from > to) {
			int temp = from;
			from = to;
			to = temp;
		}
		int highest = grade[from - 1];
		for (int i = from; i < to; i++)
			if (grade[i] > highest)
				highest = grade[i];
		return highest;
	}

	void updateGrade(int index, int val, vector<int> &grade) {
		grade[index - 1] = val;
	}

	void operation(char op, int a, int b, vector<int> &grade,  vector<int> &query) {
		if (op == 'Q') {
			query.push_back(highestGrade(a, b, grade));
		} else if (op == 'U') {
			updateGrade(a, b, grade);
		}
	} // 

	void solution() {
		vector<int> grade;
		vector<int> queryResult;
		int N, M;
		char op;
		int a, b;
		while (cin >> N >> M) {
			readGrade(N, grade);
			for (int i = 0; i < M; i++) {
				cin >> op >> a >> b;
				operation(op, a, b, grade, queryResult);
			}
			for (auto val : queryResult)
					cout << val << endl;
			grade.clear();
			queryResult.clear();
		}
	}
};

int main(void) {
	Solution solu;
	solu.solution();
	return 0;
}