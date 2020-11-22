// 小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
// 并且小Q对于能否被3整除这个性质很感兴趣。
// 小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。

//应该直接找规律求解，每三个数中必然存在两个数字为可以被整除的数字
// 从1到r(包括r自身的)一共可以被整除的个数  -  从1到l(不包括l)的一共可以整除的个数

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findNums(int l, int r) {
		int time1 = l / 3;
		int mod1 = l % 3;
		int count1 = time1 * 2;;
        // 整除说明包括了自身，要减去
		if (mod1 == 0)
			count1 -= 1;

		int time2 = r / 3;
		int mod2 = r % 3;
		int count2 = time2 * 2;
        // 统计到r的格式要包括自身，因此判断下余数
		if (mod2 == 2)
			count2 += 1;

		return count2 - count1;

	}
};
int main(void) {
	int l, r;
	cin >> l >> r;
	Solution solution;
	cout << solution.findNums(l ,r) << endl;
	return 0;
}