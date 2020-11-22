//  缓存替换算法
//  页面置换算法
//  核心思想： 利用链表实现最近最久未使用算法
//  主要的对外接口： 缓存的查找（是否命中） 缓存的删除  缓存的替换
//  当命中，则把节点提到链表的首，成为第一个元素即可，然后直接返回缓存的节点的指针
//  当不命中，则返回nullptr
//  当需要插入，则插入到头节点，并且把链表尾部的元素删除
//  如果仅仅使用链表，查找的事件复杂度为O(n)，为了提高查找的效率
//  结合哈希表，使得查找的效率为O(1)

#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

struct LRUNode {
	int key;
	int value;
	LRUNode *prev;
	LRUNode *next;
	LRUNode() : key(0), value(0), prev(nullptr), next(nullptr) { }
};

class LRUCache {
public:
	LRUCache(int cap = DEFAULT_SIZE) :
		capacity(cap), head(nullptr), tail(nullptr), count(0) { }
	~LRUCache() {
		while (tail) {
			auto temp = tail;
			tail = tail->next;
			delete temp;
		}
	};

public:
	LRUNode find(int key);
	LRUNode add(int key, int value);

private:
	void removeLast();
	void insertIntoHead(LRUNode *node);

private:
	static const int DEFAULT_SIZE = 16;
	unordered_map<int LRUNode *> nodeMap;
	LRUNode *head;
	LRUNode *tail;
	int capacity;
	int count;
};
 
int LRUCache::DEFAULT_SIZE;

void removeLast() {
	assert(tail);
	// 可能删除的是链表中唯一一个元素，注意判断这种情况
	auto temp = tail;
	if (tail == head) {
		head = tail = nullptr;
		count = 0;
	} else {
		tail->prev->next = nullptr;
		count--;
	}
	nodeMap.erase(temp->key);
	delete temp;
}

void insertIntoHead(LRUNode *node) {
	//  本身就是第一个节点，则无需变动
	//  同时，也有可能当前节点是尾部节点
	assert(node);
	if (node == head) {
		return;
	} else if (node = tail) {
		tail = node->prev;
		node->prev->next = nullptr;
		node->next = head;
		head = node;
	} else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->next = head;
		head = node;
	}
}

LRUNode *LRUCache::find(int key) {
	auto ret = nodeMap.find(key);
	if (ret != nodeMap.end()) {
		insertIntoHead(ret->second);
		return ret->second;
	}
	return nullptr;
}

LRUNode *LRUCache::set(int key, int value) {
	// TODU
}