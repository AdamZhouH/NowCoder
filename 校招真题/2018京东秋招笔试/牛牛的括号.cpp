#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	void canMatch();
};

// 这样做不能AC，"))(("实际上也是可以交换一次的，按照这个做法，则输出No
// 同时，除了"()"这一情况外，其他本身就能匹配的括号序列通过交换一次仍然是匹配的
// 下面做法的错误性：首先，括号匹配中是不建议")"入栈的，保证只"("入栈，再去分析不会被干扰
// 思路：
// 第一，排除"()"这种特殊情况
// 第二，遍历栈，如果（直接入栈
//              如果），判断当前栈是否为空，如果非空，则出栈一个（，因为我们保证了仅仅（才能入栈
//                                       如果为空，那么现在则是必须要交换一次的，交换一次也就是变换两处的括号
//                                       我们把此处的）变为（，然后入栈这个（，但是要标记这个字符已经交换了一次
// 接着遍历，如果遇到此时字符为），但是栈空，并且已经使用了一次交换，那么之前我们使用了）->（的变换，剩下一次只能是
// （->）的变换，因此，当出现这种情况后，）不能变为（了，这个字符一定不能匹配，直接break

// 结果分析，如果交换没有使用，并且栈为空，则说明本身匹配的，因为我们排除了特殊情况，因此本身匹配的字符，交换一次还是可以匹配
//                          如果栈不为空，说明，字符序列后面的字符，有一部分落单，（）数量不相同，这显然不能匹配
//          如果交换已经使用了，并且此时栈大小为2，说明栈中是两个（，那么此时另一次变换派上用场，必然可以满足要求
//                            如果此时栈大小为其他，则说明，无法一次交换来满足最终的匹配
// 算法修改如下

void Solution::canMatch() {
	vector<string> input;
	vector<string> result;
	string str;
	int n;
	cin >> n;
	while (n--) {
		cin >> str;
		input.push_back(str);
	}
/**
	for (int i = 0; i < input.size(); i++) {
		stack<char> match;
		for (int j = 0; j < input[i].size(); j++) {
			if (input[i][j] == '(')
				match.push(input[i][j]);
			if (input[i][j] == ')')
				if (!match.empty() && match.top() == '(') {
					match.pop();
					continue;
				} else {
					match.push(input[i][j]);
				}
		}
		if (match.size() == 2) {
			char left = match.top();
			match.pop();
			char right = match.top();
			if (left == '(' && right == ')')
				result.push_back("Yes");
			else 
				result.push_back("No");
		} else {
			result.push_back("No");
		}
	}
*/	
	for (int i = 0; i < input.size(); i++) {
		if (input[i].size() == 2 && input[i][0] == '(' && input[i][1] == ')') {
			result.push_back("No");
			continue;
		} 
		stack<char> sta;
		bool flag = 0;
		int j;
		for (j = 0; j < input[i].size(); j++) {
			if (input[i][j] == '(')
				sta.push('(');
			else {
				if (!sta.empty())
					sta.pop();
				else {
					if (flag)
						break;
					else {
						flag = 1;
						sta.push('(');
					}
				}
			}
		}
		// 分析结果
		if (j == input[i].size()) {      // 说明遍历完了整个字符串
			if (!flag) {                  // 没有使用交换
				if (sta.empty())
					result.push_back("Yes");
				else
					result.push_back("No");
			} else {
				if (sta.size() == 2)
					result.push_back("Yes");
				else
					result.push_back("No");
			}
		} else {                         // 没有遍历完整个字符串就跳出
			result.push_back("No");
		}
	}
	for_each(result.begin(), result.end(), [] (const string &s) { cout << s << endl; } );
}

int main(void) {
	Solution solu;
	solu.canMatch();
	return 0;
}