#include <iostream>
#include <queue>
#include <assert.h>
using namespace std;

class Solution {
public:
	// 显然，利用这种模拟的方法思路非常简单，但是开销非常之大，而且涉及内存多次的申请释放
	// 应当通过找规律的思路，发现喝饮料的人和饮料编号之间的关系，避免直接进行模拟
	char getPerson(int N) {
		// 初始阶段，队列中四人
		queue<char> q;
		q.push('A'); q.push('B'); q.push('C'); q.push('D');
		// 开始模拟喝饮料过程
		char person;
		for (int i =1; i <= N; i++) {
			assert(!q.empty());
			person = q.front();
			q.pop();
			q.push(person); q.push(person);		
		}
		return person;
	}
	// 找规律思路
	// 第一次，前四瓶各是abcd四人，然后人数变为8个人
	// 第二次，接下来的8瓶分别是aabbccdd喝完，然后人数变成16人（aaaabbbbccccdddd）
	// 以此类推，发现，再2每间隔2^i次幂之后算新的一轮，都是从a开始喝饮料，喝完这一轮后，人数加倍
	// 第一轮 4人 4瓶饮料 初始状态abcd    每种人1个
	// 第二轮 8人 8瓶饮料 初始状态aabbccdd 每种人2个
	// 第三轮 16人 16瓶饮料 初始状态aaaabbbbccccdddd 每种人4个
	// 第四轮 32人 32拼饮料 初始状态。。。。（省略）   每种人8个
	// ....类推
	char getPersonName(long N) {
		assert(N > 0);
		int i = 1;     // 记录当前喝饮料轮次的每种人的个数
		int sum = i * 4;
		while (N > sum) {
			i *= 2;
			sum += i * 4;
		}
		sum -= i * 4;
		assert(N >= sum);
		long lastRound = N - sum;

		if (lastRound <= i * 1)
			return 'A';
		else if (lastRound <= i * 2)
			return 'B';
		else if (lastRound <= i * 3)
			return 'C';
		return 'D';
	}
};

int main(void) {
	int n;
	Solution solu;
	while (cin >> n) {
//		cout << "模拟：   喝饮料的人是：" << solu.getPerson(n) << endl;
		cout << "找规律： 喝饮料的人是：" << solu.getPersonName(n) << endl;
	}
	return 0;
}