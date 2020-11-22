#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	void findLastOfOne(const string &str);
};

void Solution::findLastOfOne(const string &str) {
	if (str.empty()) {
		cout << "NULL" << endl;
		return;
	}
	map<char, size_t> records;
	for (int i = 0; i < str.size(); i++) {
		records[str[i]]++;
	}	
	// 反向遍历
	for (int i = str.size() - 1; i >= 0; i --) {
		if (records[str[i]] == 1) {
			cout << str[i] << endl;
			return;
		}
	}
	cout << "NULL" << endl;
	return;
}

int main(void) {
	string str;
	Solution solu;
	cin >> str;
	solu.findLastOfOne(str);
	return 0;
}