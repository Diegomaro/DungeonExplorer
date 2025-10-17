#include <iostream>
#include "DoubleLinkedList.hpp" //necesiario para evitar errores en vscode

template <typename T>
DoubleLinkedList<T>::Node::Node() {
	_next = nullptr;
	_prev = nullptr;
}

template <typename T>
DoubleLinkedList<T>::Node::Node(T data) {
	_data = data;
	_next = nullptr;
	_prev = nullptr;
}
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
	_head = nullptr;
	_tail = nullptr;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	clear();
}

template <typename T>
bool DoubleLinkedList<T>::insertHead(T data) {
	Node *newNode = nullptr;
	newNode = new(std::nothrow) Node(data);
	if(!newNode)
		return false;

	newNode->_next = _head;
	if(_head){
		_head->_prev = newNode;
	}
	_head = newNode;
	if(!_head->_next){
		_tail = _head;
	}
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::insertTail(T data){
	Node* newNode = new(std::nothrow) Node(data);
	if(!newNode) return false;
	
	if(!_head){
		_head = newNode;
		_tail = _head;
		return true;
	}
	_tail->_next = newNode;
	newNode->_prev = _tail;
	_tail = newNode;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::InsertNodeInOrder(T data){
	Node* tmp = _head;
	while(tmp){
		if(tmp->_data >= data){
			if(!tmp->_prev) return insertHead(data);
			else if(!tmp->_next) return insertTail(data);
			else{
				Node* newNode = new(std::nothrow) Node(data);
				if(!newNode) return false;
				tmp = tmp->_prev;
				Node* tmpNext = tmp->_next;
				tmp->_next = newNode;
				newNode->_prev = tmp;
				newNode->_next = tmpNext;
				tmpNext->_prev = newNode;
				return true;
			}
		} else if(!tmp->_next) return insertTail(data);	
		tmp = tmp->_next;
	}
	return false;
}

template <typename T>
bool DoubleLinkedList<T>::deleteHead(){
	if(!_head){
		return false;
	}
	if(_head == _tail){
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return true;	
	}
	Node* temp = _head->_next;
	temp->_prev = nullptr;
	delete _head;
	_head = temp;
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteTail(){
	if(!_tail){
		return false;
	}
	if(_head == _tail){
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return true;
	}

	Node* temp = _tail;
	temp = _tail->prev;
	delete _tail;
	_tail = temp;
	_tail->_next = nullptr;
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteNode(T data){
	if(!_head){
		return false;
	}
	if((_head == _tail) && (_head->_data == data)){
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return true;
	}
	Node* tmp = _head;
	if(_head->_data == data){
		tmp = tmp->_next;
		delete _head;
		_head = tmp;
		_head->_prev = nullptr;
		return true;
	}
	while(tmp->_next != nullptr){
		if(tmp->_next->_data == data){
			Node* anchorNode = tmp->_next->_next;
			delete tmp->_next;
			tmp->_next = anchorNode;
			if(anchorNode == nullptr){
				_tail = tmp;
			} else{
				anchorNode->_prev = tmp;
			}
			return true;
		}
		tmp = tmp->_next;
	}
	return false;
}

template <typename T>
bool DoubleLinkedList<T>::deleteNode(Node* node){
	if(!node){
		return false;
	}
	if(!node->_prev){
		return deleteHead();
	}
	if(!node->_next){
		return deleteTail();
	}
	Node* prevNode = node->_prev;
	Node* nextNode = node->_next;
	delete node;
	prevNode->_next = nextNode;
	nextNode->_prev = prevNode;
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::printAll(){
	if(!_head){
		return false;
	}
    Node* index = nullptr;
	index = _head; 
	std::cout << "lista:" << std::endl;
    while(index != nullptr){
        std::cout << "Room with: " <<index->_data << std::endl;
        index = index->_next;
    }
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty(){
	if(_head) return false;
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::clear(){
	if(!_head){
		return false;
	}
	Node* index = _head;

	while(index != nullptr){
		index = index->_next;
		delete _head;
		_head = index;
	}
	_tail = nullptr;
	return true;
}