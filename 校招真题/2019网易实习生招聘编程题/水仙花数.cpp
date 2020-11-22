#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>
using namespace std;

class Solution {
public:
	void printDaffodil(int m, int n);
	inline bool judge(int var);
};

inline
bool Solution::judge(int var) {
	int a = var / 100;
	int b = (var - (a * 100) ) / 10;
	int c = var - a * 100 - b * 10;
	if ((pow(a, 3) + pow(b, 3) + pow(c, 3)) == var)
		return true;
	return false;
}

void Solution::printDaffodil(int m, int n) {
	int count = 0;
	for (int i = m; i < n; i++) {
		if (judge(i)) {
			count++;
			cout << i << " ";
		}
	}
	if (count == 0)
		cout << "no" << endl;
    cout << endl;
}

int main(void) {
    int var;
    vector<int> vec;
    while (cin >> var) {
        vec.push_back(var);
    }
    Solution solution;
    for (int i = 0; i < vec.size(); i += 2)
        solution.printDaffodil(vec[i], vec[i + 1]);
    return 0;
}