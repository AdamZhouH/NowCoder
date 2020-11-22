#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

// 主要是需要定义一种比较序
// 数字组成的字符串A + B > B + A 则A > B，按照此标准定义序即可
// （个人是先转换为字符串，然后逆序，然后开始比较）

struct cmp {
    bool operator () (int lhs, int rhs) {
        string a = to_string(lhs) + to_string(rhs);
        string b = to_string(rhs) + to_string(lhs);
        return a > b;
    }
};

class Solution {
public:
    string getMax(int n);
};

string Solution::getMax(int n) {
    vector<int> nums;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        nums.push_back(val);
    }
    string ret = "";
    sort(nums.begin(), nums.end(), cmp());
    for (int i = 0; i < n; i++) {
        ret += to_string(nums[i]);
    }
    return ret;
}

int main(void) {
    Solution solu;
    int n;
    while (cin >> n) {
        cout << solu.getMax(n) << endl;
    }
    return 0;
}