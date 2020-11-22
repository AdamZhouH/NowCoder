#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
	void solution(istream &is) {
		map<pair<string, size_t>, size_t> records;
		string lineContent;
		while (getline(is, lineContent)) {
			if (!lineContent.empty()) {
				istringstream line(lineContent);
				string filePath, fileName;
				size_t lineNo;
				line >> filePath >> lineNo;
				// 文件名可能存在路径
				auto pos = filePath.rfind('\\');
				if (pos == string::npos)
					fileName = filePath;
				else
					fileName = filePath.substr(pos + 1);
				++records[make_pair(fileName, lineNo)];
			}
		}

		for (auto it = records.begin(); it != records.end(); it++) {
			results.push_back(tuple<string, size_t, size_t> ((*it).first.first, (*it).first.second, (*it).second));
		}
		stable_sort(results.begin(), results.end(), [] (const tuple<string, size_t, size_t> &lhs, const tuple<string, size_t, size_t> &rhs) { 
												  		return get<2>(lhs) > get<2>(rhs);   // 少了return真是要死人的 ！！！！！
												  });

		// Output
		for (int i = 0; i < results.size() && i < 8; i++) {
			string file = get<0>(results[i]);
			if (file.size() > 16) {
				cout << file.substr(file.size() - 16) << ' ' << get<1>(results[i]) << ' ' << get<2>(results[i]) << endl;
			} else {
				cout << file << ' ' << get<1>(results[i]) << ' ' << get<2>(results[i]) << endl;
			}
		}
	}
};

int main(void) {
	Solution solu;
	solu.solution(cin);
	return 0;
}