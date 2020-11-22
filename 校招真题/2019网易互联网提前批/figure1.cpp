#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <new>
#include <stack>
#include <deque>
#include <queue>
#include <utility>
#include <memory>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
	void find() {
		int n;
		cin >> n;
		int var;
		int *heaps = new int[n];

		for (int i = 0; i < n; i++) {
			cin >> var;
			heaps[i] = var;
		}

		int m;
		cin >> m;
		int *request = new int[m];
		int *result = new int[m];

		for (int i = 0; i < m; i++) {
			cin >> var;
			request[i] = var;
		}

		// 数组求和
		int sum = 0; 
		int *judge = new int[n];
		for (int i = 0; i < n; i++) {
			sum += heaps[i];
			judge[i] = sum;
		}

		// 查找 这是超时的做法，以后对于这种有序的查找，第一个应该想到的是二分查找算法
		/***********************************
		for (int i = 0; i < m; i++) {
			int count = request[i];
			int j;
			for (j = 0; j < n; j++) {
				if (count <= judge[j])
					break;
			}
			result[i] = j + 1;
		}
		************************************/

		// 改为利用二分进行查找
		for (int i = 0; i < m; i++) {
			int low = 0, high = n - 1;
			int mid;
			while (low <= high) {
				mid = (high - low) / 2 + low;
				if (judge[mid] >= request[i] && judge[mid - 1] < request[i])
					break;
				else if (judge[mid] > request[i])
					high = mid - 1;
				else 
					low = mid + 1;
			}
			result[i] = mid + 1;
		}

		// 输出
		for (int i = 0; i < m; i++) {
			cout << result[i] << endl;
		}
	}
};

int main(void) {
	Solution solu;
	solu.find();
	return 0;
}