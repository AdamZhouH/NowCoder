#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const string POSITION = "NESW";

class Solution {
public:
    char direction(const string &behaviors);
};

char Solution::direction(const string &behaviors) {
	int count = 0;
	for_each(behaviors.begin(), behaviors.end(), [&count](char c) {
		if (c == 'L')
			count--;
		else
			count++;
	});
	count %= 4;
	if (count < 0)
		count += 4;
	return POSITION[count];
}

int main(void) {
	Solution solution;
	int n;
	string s;
	cin >> n >> s;
	cout << solution.direction(s) << endl;
	return 0;
}