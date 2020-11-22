#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void getXY();
};

void Solution::getXY() {
	vector<string> result;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long var;
		cin >> var;
		if (var % 2 != 0 ) {
			result.push_back("No");
			continue;
		}
		if (var == 2) {
			result.push_back(string() + to_string(2) + " " + to_string(1));
			continue;
		}

		for (int j = 3; ; j += 2) {
			if (var % j == 0) {
				result.push_back(string() + to_string(j) + " " + to_string(var / j));
				break;
			}
		}
	}
	// 输出结果
	for_each(result.begin(), result.end(), [] (const string &s) {cout << s << endl; } );
}

int main(void) {
	Solution solu;
	solu.getXY();
	return 0;
}