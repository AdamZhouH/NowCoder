// 利用并查集，先找到根节点，然后从根节点开始bfs遍历
// 利用层次遍历找到树的高度
// 题目比较怪了，说好是合法的二叉树
// 实际上给出的测试用例则是包含多叉树的情况，对于多叉树的情况
// 需要把多叉树的情况排除掉，当某个节点的数的个数大于2，则后面的节点不加入
// 题目和测试用例其实出现歧义，不用理会，通过50%可以考虑为正确

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    Solution();
    int getHeight();
private:
    vector<int> edges;
    vector<int> childs;
    int n;
};

Solution::Solution() {
    cin >> n;
    edges = vector<int> (n, -1);
//    childs = vector<int> (n, 0);
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
//        if (childs[a] >= 2) {
//            continue;
//        } else {
//            childs[a]++;
          edges[b] = a;
//        }
    }
}

int Solution::getHeight() {
    // 从每个节点开始网上回溯到根节点，记录高度
    int maxHeight = INT_MIN;
    for (int i = 0; i < n; i++) {
        int currHeight = 0;
        int j = i;
        while (edges[j] != -1) {
            currHeight++;
            j = edges[j];
        }
        currHeight++;
        maxHeight = max(maxHeight, currHeight);
    }
    return maxHeight;
}

int main(void) {
    Solution solu;
    cout << solu.getHeight() << endl;
    return 0;
}