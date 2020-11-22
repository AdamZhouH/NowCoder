#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 签到题，没啥好说的

class Solution {
public:
	int diff() {
		int n, sum = 0;
		int val;
		vector<int> vec;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> val;
			sum += val;
			vec.push_back(val);
		}
		sort(vec.begin(), vec.end(), [] (int a, int b) { return a > b; });
		for (int i = 1; i < n; i += 2)
			sum -= 2 * vec[i];
		return sum;
	}
};

int main(void) {
	Solution solu;
	cout << solu.diff() << endl;
	return 0;
}