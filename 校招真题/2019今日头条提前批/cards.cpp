// 洗牌算法的简单实现
// 时间复杂度和空间复杂度都是O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int> cards, int k) {
    vector<int> helper(cards.size(), -1);
    while (k-- != 0) {
        // 每一次洗牌
        for (int i = 0; i < cards.size(); i++) {
            if (i < cards.size() / 2)
                helper[i * 2] = cards[i];
            else 
                helper[(i - cards.size() / 2) * 2 + 1] = cards[i];
        }

        cards = helper;
 //       helper.clear();
    }
    // 输出k次洗牌之后的结果
    for (int i = 0; i < cards.size(); i++) {
        if (i != cards.size() - 1)
            cout << cards[i] << ' ';
        else
            cout << cards[i] << endl;
    }
}

int main(void) {
    int T, n, k;
    int val;
    vector<int> cards;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < 2 * n; i++) {
            cin >> val;
            cards.push_back(val);
        }
        reverse(cards, k);
        cards.clear();
    }
    return 0;
}
