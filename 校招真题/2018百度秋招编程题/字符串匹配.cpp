#include <iostream>
#include <set>
#include <string>
using namespace std;

// 思路，利用dfs先把b中的?空填满，产生的字符串都放到set中，避免重复
// 然后针对每个字符串都和a匹配一下就行
// 牛客上提交，结果超过内存限制
// 算法需要优化
// 优化方法就是，我们不求出所有的可能的b
// 但是把a中所有的和b等长的字符子串分割出来，放入一个set中
// 这样保证了set中不会存在过多的字符串从而导致内存不足

/*
class Solution {
public:
	int match(const string &a, const string &b);
	void getAllString(set<string> &ret, const string &s, int pos, string &curr);
};

void Solution::getAllString(set<string> &ret, const string &s, int pos, string &curr) {
	if (pos == s.size()) {
		ret.insert(curr);
		return;
	}
	// 判断当前字符是否是'?'
	if (s[pos] != '?') {
		getAllString(ret, s, pos + 1, curr.append(1, s[pos]));
	} else {
		getAllString(ret, s, pos + 1, curr.append(1, '0'));
		curr.pop_back();
		getAllString(ret, s, pos + 1, curr.append(1, '1'));
	}
	// 回溯
	curr.pop_back();
}

int Solution::match(const string &a, const string &b) {
	if (b.size() > a.size() || b.empty() || a.empty())
		return 0;
	set<string> ret;
	string curr;
	getAllString(ret, b, 0, curr);
	if (ret.empty())
		return 0;
	int count = 0;
	for (auto &s : ret) {
		if (a.find(s) != string::npos)
			count++;
	}
	return count;
}

int main(void) {
	Solution solu;
	string a, b;
	while (cin >> a >> b) {
		cout << solu.match(a, b) << endl;
	}
	return 0;
}
*/

class Solution {
public:
	int match(const string &a, const string &b);
};

int Solution::match(const string &a, const string &b) {
	if (b.size() > a.size())
		return 0;
	set<string> split;
	int len = b.size();
	for (int i = 0; i + len - 1 < a.size(); i++) {
		split.insert(a.substr(i, len));
	}
	int count = 0;
	// 逐个判断
	for (auto it = split.begin(); it != split.end(); it++) {
		const string &s = *it;
		int i;
		for (i =0; i < len; i++) {
			if (s[i] != b[i] && b[i] != '?') {
				break;
			}
		}
		if (i == len)
			count++;
	}
	return count;
}

int main(void) {
	string a, b;
	Solution solu;
	while (cin >> a >> b) {
		cout << solu.match(a, b) << endl;
	}
	return 0;
}