#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


int main(void) {
	string v1, v2;
	cin >> v1 >> v2;
	vector<char> a(v1.rbegin(), v1.rend()), b(v2.rbegin(), v2.rend());
	vector<char> result;
	for (int i = 0; i < b.size(); i++) {
		deque<char> temp;
		int carray = 0;
		for (int j = 0; j < a.size(); j++) {
			int val = (a[j] - '0') * (b[i] - '0') + carray;
			temp.push_back(val % 10 + '0');
			carray = val / 10;
		}
		if (carray)
			temp.push_back(carray + '0');
		for (int k = 0; k < i; k++)
			temp.push_front('0');
		// 执行一次加法
		if (result.empty()) {
			for (int k = 0; k < temp.size(); k++)
				result.push_back(temp[k]);
		} else {
			int m = 0, n = 0;
			int carray = 0;
			while (m < result.size() && n < temp.size()) {
				int val = result[m] - '0' + temp[n] - '0' + carray;
				result[m] = val % 10 + '0';
				carray = val / 10;
				m++, n++;
			}
			if (m < result.size()) {
				for (; m < result.size(); m++) {
					int val = result[m] - '0' + carray;
					result[m] = val % 10 + '0';
					carray = val / 10;
				}
			} else if (n < temp.size()) {
				for (; n < temp.size(); n++) {
					int val = temp[n] - '0' + carray;
					result.push_back(val % 10 + '0');
					carray = val / 10;
				}
			}
			if (carray)
				result.push_back(carray + '0');
		}
	}
	for(int i = result.size() - 1; i>= 0; i--)
		cout << result[i];
	cout << endl;
	return 0;
}