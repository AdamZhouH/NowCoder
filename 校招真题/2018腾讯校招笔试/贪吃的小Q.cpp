#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 这道题目一看很像是数学题目，比较明显的等比数列，如果不限制，公比为1/2
// 但是不是完全的等比数列，因为每次吃的巧克力数目要是整数的
// 想到利用迭代，计算，第一天吃x块巧克力，那么N天一共需要多少块巧克力
// 如此，那么我们一共吃的巧克力数目则需要刚好等于总共的巧克力数目
// 从而找到第一天最多吃几块巧克力
// 因此是一个二分查找的问题

class Solution {
public:
	int getTotal(int val, int N) {
		int total = 0;
		for (int i = 0; i < N; i++) {
			total += val;
			val = (val + 1) / 2;
		}
		return total;
	}

	int getMaxFirstDay() {
		int N, M;
		int low, high, middle;
		int total;
		cin >> N >> M;
		low = 1, high = M;
		// 二分查找的过程
		while (low <= high) {
			middle = (low + high) / 2;
			total = getTotal(middle, N);
			if (total == M)
				return middle;
			if (total > M)
				high = middle - 1;
			else
				low = middle + 1;
		}
		if (getTotal(low, N) > M) // 这里一点很重要，因为问题具有实际意义，不是完全单独的二分查找，还必须满足总数<M
			return low - 1;       // 而代码中的二分也没有判断是否找到，还要加一个判断
		return low;
	}
};

int main(void) {
	Solution s;
	int result = s.getMaxFirstDay();
	cout << result << endl;
	return 0;
}