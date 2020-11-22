#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string valid(const string &str);
};

string Solution::valid(const string &str) {
	stack<char> s;
	deque<char> ret;

	for (int i = 0; i < str.size(); i++) {
		ret.push_back(str[i]);
		if (str[i] == '[') {
			s.push('[');
		} else if (str[i] == ']') {
			if (s.empty()) {
				ret.push_front('[');
			} else 
				s.pop();
		}
	}
	while (!s.empty()) {
		s.pop();
		ret.push_back(']');
	}
	return string(ret.begin(), ret.end());
}

int main(void) {
	string s;
	Solution solu;
	while (cin >> s) {
		cout << solu.valid(s) << endl;
	}
	return 0;
}