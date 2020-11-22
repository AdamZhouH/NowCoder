#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
	void reverseWords();
};

void Solution::reverseWords() {
	string ret;
	string line;
	getline(cin, line);
	istringstream input(line);
	string word;
	while (input >> word) {
		// 反转单个单词
		int i = 0; int j = word.size() - 1;
		while (i < j) {
			char c = word[i];
			word[i] = word[j];
			word[j] = c;
			i++; j--;
		}
		// 单词输入到ret
		ret = ret + word + " ";
	}
	// 除去最后的空格
	ret.pop_back();
	cout << ret << endl;
}

int main(void) {
	Solution solu;
	solu.reverseWords();
	return 0;
}