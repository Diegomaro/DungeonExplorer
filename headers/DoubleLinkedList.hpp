#pragma once
template <typename T>
class DoubleLinkedList {
public:
	class Node {
	public:
		T _data;
		Node *_next;
        Node* _prev;
		Node();
		Node(T data);
	};

	DoubleLinkedList();
	~DoubleLinkedList();
	bool insertHead(T data);
	bool insertTail(T data);
	bool InsertNodeInOrder(T data); // for player
	bool deleteHead();
	bool deleteTail();
	bool deleteNode(T data);
	bool deleteNode(Node* node);
	bool printAll();
	bool isEmpty();
	bool clear();
private:
	Node *_head;
	Node *_tail;
};
#include "DoubleLinkedList.tpp"