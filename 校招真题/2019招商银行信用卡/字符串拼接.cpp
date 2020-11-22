#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
	void canJoint(const string &s);
};

// 最大的字串长度为 n/2，如果不行再-1，一直到字串长度为1，如果都不行，则输出不行
// 如果可行，那么在迭代过程中，第一次满足拼接的字串的长度就是所求的最大长度，然后推出循环，直接输出即可
// 当给定一个子串的长度时候，先判断长度是否可以整除整个字符串的长度，可以的话，才有下一步，否则直接continue
// 判断的具体步骤则是，确定了子串长度之后，子串也就确定了，然后从原字符串第二个子串应该在的位置开始逐个判断即可

void Solution::canJoint(const string &s) {
	int len = s.size();
	if (len <= 1) {
		cout << "false" << endl;
		return;
	}
	// i为当前长度
	for (int i = len / 2; i >= 1; i--) {

		if (len % i != 0)
			continue;
		int j = 0;
		for (; j < len; j++) {
			// 这里利用j % i而不是多个循环进行判断，实在是比较巧妙，学习了！
			if (s[j] != s[j % i])
				break;
		}
		if (j < len) {
			continue;
		} else {
			cout << s.substr(0, i) << endl;
			return;
		}

	}
	cout << "false" << endl;
}

int main(void) {
	Solution solu;
	string s;
	while (cin >> s) 
		solu.canJoint(s);
	return 0;
}