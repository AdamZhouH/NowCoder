// 图上画出大概出队的方向，可知，先把对头放入对尾部，然后再pop出一个队头
// 那么逆序回去，也即是，先让最后出队元素，插入辅助队列的对尾部，然后把辅助队
// 的队头元素出队并放入辅助队列对尾即可
// 依次迭代，发现最后得到的序列是原始队列序列的逆序
// 最后reverse一下即可
// 关键在于数据结构的选择
// 对于输入，用栈保存
// 辅助队列用队列表示就行
// 题目思路也非常清晰，关键是先找到规律，如何逆序回去，考察逆向思维
// 时间复杂度O(n)，空间复杂度也是O(n)

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void restore(stack<int> &s);
int main(void) {
    int n, val;
    cin >> n;       // n组数据
    while (n-- != 0) {
        cin >> val;
        stack<int> s;
        for (int i = 1; i <= val; i++)
            s.push(i);
        restore(s);
    }
    return 0;
}

void restore(stack<int> &s) {
    // 辅助队列
    queue<int> q;
    while (!s.empty()) {
        auto t = s.top();
        s.pop();
        q.push(t);
        auto h = q.front();
        q.pop();
        q.push(h);
    }
    // 最后再把队列输出到栈（因为此时队列中顺序和原始的刚好是相反的）
    while (!q.empty()) {
        auto t = q.front();
        s.push(t);
        q.pop();
    }
    // 最后输出原来的顺序
    while (!s.empty()) {
        auto t = s.top();
        s.pop();
        if (s.empty())
            cout << t << endl;
        else 
            cout << t << ' ';
    }
}