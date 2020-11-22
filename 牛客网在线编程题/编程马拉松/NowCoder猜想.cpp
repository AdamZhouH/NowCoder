// write your code here cpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 暴力方法判断素数
class Solution {
public:
    int getPrime(int n);
};

int Solution::getPrime(int n) {
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    int count = 2;
    for (int i = 4; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            count++;
    }
    return count;
}

int main(void) {
    Solution solu;
    int val;
    while (cin >> val) {
        cout << solu.getPrime(val) << endl;
    }
    return 0;
}