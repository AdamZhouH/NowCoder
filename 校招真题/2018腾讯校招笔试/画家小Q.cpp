#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
	char board[60][60];
public:
	int leastTimes() {
		// 处理输入数据，利用动态数组存储
		int n, m;
		cin >> n >> m;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < m; j++) {
				board[i][j] = s[j];
			}
		}
		// Test : Print Board
/*		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << board[i][j] << ' ';
			cout << endl;
		}
*/		
		// Test : Print Board

		// 算法思路：这种类似图的题目，用矩阵中的字符表示不同的图的状态，一般考虑用图的遍历的算法
		// 比如DFS比如BFS比如两者结合
		// 这道题目，和之前再Leetcode上刷过得一套岛屿题目类似
		// 遍历，然后清除标记，从而找到岛屿的数目，这道题目的情景换了一下

		// 首先是，标记分为四种 B Y X G ，其中除了X表示空白，其他都是颜色
		// 其实，标记是相关联的，如果两个标记为 B Y，则叠加变成G标记
		// 要求最短的画数，则需要让每一笔画连接尽可能多的像素格
		// 那么每次碰到一个颜色格子，则按照规定的方向往两个方向搜索，并在遇到相应的颜色的时候，标记为空白或者减一种颜色
		// 直到遇不到颜色或者超出空白

		// 具体流程：
		// 遍历矩阵，遇到蓝色，则计数+1，然后标记为空白，然后往左下和右上两个方向进行遍历
		// 把遇到蓝色的标记为空白，遇到绿色的标记为黄色（减去一种颜色），直到达到边界或者遇到空白

		// 同理遇到黄色

		// 对于遇到绿色，则一定是两条笔画相交，因此，计数+2，然后现在此点上进行遇到蓝色的遍历行为
		// 再进行作为遇到黄色的遍历行为（因为是两种颜色叠加的）

		// 上述遍历行为使用dfs完成，总体思路如上。

		// 算法证明？？？为何这样的贪心算法可以保证的确是使得笔画数最少？？反证？

		int count = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'B') {
					blueDfs(n, m, i, j);
					count++;
				} else if (board[i][j] == 'Y') {
					yellowDfs(n, m, i, j);
					count++;
				} else if (board[i][j] == 'G') {
					blueDfs(n, m, i, j);
					board[i][j] = 'Y';
					yellowDfs(n, m, i, j);
					count += 2;
				}
			}
		return count;
	}

	void blueDfs(int n, int m, int x, int y) {
		if (x >= 0 && x < n && y >= 0 && y < m && (board[x][y] == 'B' || board[x][y] == 'G')) {
			if (board[x][y] == 'B') {
				board[x][y] = 'X';
			} else {
				board[x][y] = 'Y';
			}
			blueDfs(n, m, x + 1, y - 1);
			blueDfs(n, m, x - 1, y + 1); 
		}
		return;
	}

	void yellowDfs(int n, int m, int x, int y) {
		if (x >= 0 && x < n && y >= 0 && y < m && (board[x][y] == 'Y' || board[x][y] == 'G')) {
			if (board[x][y] == 'Y') {
				board[x][y] = 'X';
			} else {
				board[x][y] = 'B';
			}
			yellowDfs(n, m, x + 1, y + 1);
			yellowDfs(n, m, x - 1, y - 1); 
		}
		return;
	}
	
};

int main(void) {
	Solution solu;
	cout << solu.leastTimes() << endl;
	return 0;
}