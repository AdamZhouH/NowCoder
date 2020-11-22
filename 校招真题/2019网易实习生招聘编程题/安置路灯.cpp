// 解题思路
// 一开始，好像很不好确定具体该怎么放置路灯的算法
// 通过画出草图帮助理解
// 首先明确 一盏路灯最多照亮三个位置
// 第二点 不需要照亮的地方也可以放置路灯或者被照亮，但那并不是我们的刻意要求
// 我们始终保证需要照亮的地方必须照亮即可
// 从一个给定的字符串，我们从头开始遍历，找到第一个需要照亮的地方，先不放置路灯灯，考虑从这里开始的连续三个位置的情况
// 可能的情况有 ...   .x.   ..x   .xx  但是其实都只是需要一盏路灯，隔开三个位置后，我们再找到余下的第一个.的位置
// 做如上的同样处理
// 遍历完毕后，得出结果

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(char c) {
	return c == '.';
}

class Solution {
public:
    int lightNums(const string &s);
};

int Solution::lightNums(const string &s) {
    int count = 0;
    auto it = s.begin();
    auto end = s.end();
    while (it != s.end()) {
		it = find_if(it, end, compare);
		if (it != end) {
			count++;
			it += 3;
		} else
			break;
	}
	return count;
}

int main(void) {
	Solution solution;
	int t, n;
	string s;
	vector<string> svec;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> s;
		svec.push_back(s);
	}
	for_each(svec.begin(), svec.end(), [&solution] (const string &s) {
		int result = solution.lightNums(s);
		cout << result << endl;
	});
	return 0;
}