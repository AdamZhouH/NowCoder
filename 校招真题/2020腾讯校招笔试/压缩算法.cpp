#include <iostream>
#include <string>
using namespace std;

// 比较明显的递归思路
// 先解决最内层的某个字符串，然后递归解压其余的
// 当不存在压缩标示时，直接返回
// 注意，查找的[和]以及|必须是同一层的，要匹配
class Solution {
public:
    string unzip(string s);
};

string Solution::unzip(string s) {
    if (s.empty()) return "";
    if (s.find('[') == string::npos) return s;
    string::size_type p1 = s.find_last_of('[');
    string::size_type p2 = s.find_first_of('|', p1);
    string::size_type p3 = s.find_first_of(']', p1); 
    
    string prefix = s.substr(0, p1), suffix = s.substr(p3+1), mid = "";
    int repeats = stoi(s.substr(p1+1, p2 - p1 - 1));
    string tmp = unzip(s.substr(p2+1, p3 - p2 - 1));
    for (int i = 0; i < repeats; i++) mid = mid + tmp;
    return unzip(prefix+mid+suffix);
}
