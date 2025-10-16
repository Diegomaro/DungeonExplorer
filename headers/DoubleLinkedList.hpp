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
	bool deleteHead();
	bool deleteTail();
	bool deleteNode(T data);
	bool deleteNode(Node* node);
	bool printAll();
	bool clear();
private:
	Node *_head;
	Node *_tail;
};
#include "DoubleLinkedList.tpp"