#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
using namespace std;

// 实际上给出的是一个有向图的关系，人员是图的定点，人之间的认识关系则是图的边
// 但是，由于认识关系不具备传递性，因此还有区别
// 镇长满足的条件，出度为0,入度为n-1
// 考虑在处理每个关系的过程中，涉及到两个顶点分别的入度和出度，同时，只要一个人
// 认识了别人，他就不能够当村长了，考虑用两个数组分别存放每个人的出度和入度
// 最后遍历判断

class Solution {
public:
	void chooseBailiff(istream &is);
};

void Solution::chooseBailiff(istream &is) {
	int t, n, m, ai, bi, count;
	vector<int> in, out;
	vector<pair<int, list<int>>> result;

	is >> t;
	
	for (int i = 0; i < t; i++) {
		is >> n >> m;
		in.clear();
		out.clear();
		in.resize(n + 1, 0);
		out.resize(n + 1, 0);
		// 读取关系
		for (int j = 0; j < m; j++) {
			is >> ai >> bi;
			if (ai != bi) {
				in[bi]++;
				out[ai]++;
			} else {
				continue;
			}
		}
		/*
		if (i == 2) {
			for(auto var : in)
				cout << var << ' ';
			cout << endl;
			for (auto var : out)
				cout << var << ' ';
			cout << endl;
		}
		*/

		// 统计结果
		count = 0;
		list<int> lst;
		for (int i = 1; i <= n; i++) {
			if (in[i] == n - 1 && out[i] == 0) {
				count++;
				lst.push_back(i);
			}
		}

		// 存入结果集合
		result.push_back(pair<int, list<int>>(count, lst));
	}

	// 打印最终结果
	for (auto const &p : result) {
		if (p.first == 0) {
			cout << 0 << '\n' << endl;
		}
		else {
			cout << p.first << endl;
			for (auto var : p.second)
				cout << var << ' ';
			cout << endl;
		}
	}
}

int main(void) {
	Solution solu;
	solu.chooseBailiff(cin);
	return 0;
}