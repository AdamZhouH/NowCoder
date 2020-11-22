class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence);
	bool VerifySquenceOfBST(vector<int> &sequence, int left, int right);
};

bool Solution::VerifySquenceOfBST(vector<int> &sequence, int left, int right) {
	if (left == right)
		return true;
	int i, j;
	int root = sequence[right];
	for (i = left; i <= right - 1; i++)
		if (sequence[i] >= root)
			break;
	// 右子树存在
	if (i <= right - 1) {
		for (int j = i; j < right - 1; j++)
			if (sequence[j] < root)
				return false;
		// 左子树不存在
		if (i == left)
			return VerifySquenceOfBST(sequence, i, right - 1);
		else 
			return VerifySquenceOfBST(sequence, left, i - 1) &&
				   VerifySquenceOfBST(sequence, i, right - 1);
	} else {
	// 右子树不存在
		return VerifySquenceOfBST(sequence, left, i - 1);
	}
}

bool Solution::VerifySquenceOfBST(vector<int> sequence) {
	if (!sequence.size())
		return false;
	if (sequence.size() == 1)
		return true;
	return VerifySquenceOfBST(sequence, 0, sequence.size() - 1);
}