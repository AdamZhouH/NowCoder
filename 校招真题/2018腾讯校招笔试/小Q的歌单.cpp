#include <iostream>
#include <utility>
#include <memory>
using namespace std;
// 很明显这是一道数学组合的题目，一个可行的组合方案则是从X首A类歌单选择i首
// Y首B类歌单中选择j首，并且满足A * i + B * j = K
// 然后求得这个组合的数目，很显然，必须计算组合数，这道题目的关键点也在这里
// 如果是暴力求解每个方案的组合数，会超时，同时，很多计算是重复的。
// 这里应当考虑利用动态规划来计算组合数
// 利用矩阵C[i][j]表示从i中选择j个的组合数，那么转移方程可以是 C[i][j] = C[i-1][j-1] + C[i-1][j]
// 大致思想是：把i个分成两部分，一部分只有一个，另一部分i-1个，那么在选择j个的时候，有两种情况
// 选择单独一个，再从i-1中选择j-1个，或者直接从i-1个中选择j个，从而得到上述转移方程
// 还有一点则是，利用到了mod运算的性质，(A+B) MOD C = ((A MOD C) + (B MOD C)) MOD C
// 因此，我们每次只需要计算组合数的MOD也能保证最终计算结果的正确性，因此，减少了数据的长度。


class Solution {
public:
	static const long long MOD = 1000000007;
	static const size_t ROWS = 101, COLS = 101;
	void getTotal();
private:
	void init();
	long long C[ROWS][COLS];
};

// static成员还必须定义一次
const long long Solution::MOD;
const size_t Solution::ROWS;
const size_t Solution::COLS;

// 动态规划思想，减少对重复子问题的求解，求组合数
void Solution::init() {
	C[0][0] = 1;
	for (int i = 1; i < ROWS; i++) {
		C[i][0] = 1;
		C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
}

void Solution::getTotal() {
	init();
	int A, B, X, Y, K;
	cin >> K >> A >> X >> B >> Y;
	long long result = 0;
	for (int i = 0; i <= X; i++) {
		if (i * A <= K && (K - i * A) % B == 0 && (K - i * A) / B <= Y)
			result = (result + (C[X][i] * C[Y][(K - i * A) / B]) % MOD) % MOD;
	}
	cout << result << endl;
}

int main() {
	Solution s;
	s.getTotal();
	return 0;
}