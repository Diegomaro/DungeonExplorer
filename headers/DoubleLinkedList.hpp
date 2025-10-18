#pragma once
template <typename T>
class DoubleLinkedList {
public:
	class Node {
	public:
		T data;
		Node *next;
        Node* prev;
		Node();
		Node(T nData);
	};
	DoubleLinkedList();
	~DoubleLinkedList();
	bool insertHead(T nData);
	bool insertTail(T nData);
	bool insertNodeInOrder(T nData);
	bool deleteHead();
	bool deleteTail();
	bool deleteNode(T nData);
	bool deleteNode(Node* node);
	bool printAll();
	bool isEmpty();
	bool clear();
private:
	Node *_head;
	Node *_tail;
};
#include "DoubleLinkedList.tpp"