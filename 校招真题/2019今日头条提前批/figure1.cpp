#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

// 深度优先遍历，把所有连接到的点，设置为0
void travel(int x, int y, vector<vector<int>> &matrix, int &total) {
	int low = matrix.size();
	int col = matrix[1].size();
	if (x >= 0 && x < low && y >= 0 && y < col) {
		if (matrix[x][y] == 0) {
			return;      // 无人
		} else {
			matrix[x][y] = 0;
			total++;
			travel(x-1, y, matrix, total);
			travel(x+1, y, matrix, total);
			travel(x, y-1, matrix, total);
			travel(x, y+1, matrix, total);
			travel(x-1, y-1, matrix, total);
			travel(x-1, y+1, matrix, total);
			travel(x+1, y-1, matrix, total);
			travel(x+1, y+1, matrix, total);
		}
	}
}

int main(int argc, char const *argv[])
{
	// 数据输入
	int m, n;
	vector<vector<int>> matrix;
 
	scanf("%d,%d\n", &m, &n);
	for (int i = 0; i < m; i++) {
		matrix.push_back(vector<int>());
		int var;
		for (int j = 0; j < n; j++) {
			if (j != n - 1)
				scanf("%d,", &var);
			else
				scanf("%d\n", &var);
			matrix[i].push_back(var);
		}
	}

	// 开始遍历过程
	int count = 0;
	int max = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 0) {
				int tempmax = 0;
				count++;
				travel(i, j, matrix, tempmax);
				max = (tempmax > max ? tempmax : max);
			}
		}
	}

	printf("%d,%d\n", count, max);
	return 0;
}