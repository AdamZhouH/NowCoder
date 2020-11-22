#include <iostream>
#include <vector>

class UnionFindSet {
public:
	UnionFindSet(int n) { set.resize(n, -1); }

	void unite(int a, int b);
	int find(int val);
	bool isConnected(int a, int b);
private:
	vector<int> set;
};

int UnionFindSet::find(int val) {
	if (set[val] == -1)
		return -1;
	else 
		return find(set[val]);
}

int UnionFindSet::isConnected(int a, int b) {
	return find(a) == find(b);
}

int UnionFindSet::union(int a, int b) {
	int root1 = find(a);
	int root2 = find(b);
	if (root1 != root2) 
		set[b] = root1;
}