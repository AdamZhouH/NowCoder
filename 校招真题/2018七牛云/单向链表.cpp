#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

// 链表的倒数第k个节点
// 双指针问题

typedef struct node {
	int key;
	node *next;
} node;

class Solution {
public:
	node *theKthNode(node *head, int k);        // 链表倒数第k个节点
};

node *Solution::theKthNode(node *head, int k) {
	if (head == nullptr)
		return nullptr;
	int slow = head;
	int fast = head;
	// fast指针先走k-1步
	for (int i = 0; i < k - 1 && head; i++) {
		if (fast)
			fast = fast->next;
		else
			break;
	}
	if (!head)
		return nullptr;
	// 快慢指针同时走
	while (fast->next) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}