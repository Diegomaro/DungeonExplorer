#include <iostream>

template <typename T>
BinaryTree<T>::Node::Node(): _left(nullptr), _right(nullptr){};
template <typename T>
BinaryTree<T>::Node::Node(T data): _data(data), _left(nullptr), _right(nullptr){};

template <typename T>
BinaryTree<T>::BinaryTree(): root(nullptr) {};

template <typename T>
BinaryTree<T>::~BinaryTree(){
    clear();
}

template <typename T>
bool BinaryTree<T>::insertNode(T data){
    Node* newNode = new(std::nothrow) Node(data);
    if(!newNode){
        return false;
    }
    if(!root){
        root = newNode;
        return true;
    }
    Node* tmp = root;

    while(tmp->_left || tmp->_right){
        if(tmp->_data > data) {
            if(tmp->_left){
                tmp = tmp->_left;
            } else{
                tmp->_left = newNode;
                return true;
            }
        }
        else if(tmp->_data < data) {
            if(tmp->_right){
                tmp = tmp->_right;
            } else{
                tmp->_right = newNode;
                return true;
            }
        }
        else {
            delete newNode;
            return false; 
        }
    }
    if(data < tmp->_data){
        tmp->_left = newNode;
        return true;
    } else if (data > tmp->_data){
        tmp->_right = newNode;
        return true;
    }
    delete newNode;
    return false;
}

template <typename T>
bool BinaryTree<T>::deleteNode(T data){
    return findNodeToDelete(root, data);
}

template <typename T>
bool BinaryTree<T>::findNodeToDelete(Node *&node, T data){
    if(!node) return false;
    if(node->_data < data) {
        return findNodeToDelete(node->_right, data);
    } else if(node->_data > data) {
        return findNodeToDelete(node->_left, data);
    } else{
        deleteNodeExecute(node);
        return true;
    }
    return false;
}

template <typename T>
void BinaryTree<T>::deleteNodeExecute(Node *&node){
    if(!node->_left && !node->_right){
        delete node;
        node = nullptr;
        return;
    }
    if(!node->_left){
        Node* tmp = node->_right;
        delete node;
        node = tmp;
        return;
    }
    if(!node->_right){
        Node* tmp = node->_left;
        delete node;
        node = tmp;
        return;
    }
    Node *&tmpNode = findMinNode(node->_right);
    if(!tmpNode->_right){
        node->_data = tmpNode->_data;
        delete tmpNode;
        tmpNode = nullptr;
        return;
    }
    node->_data = tmpNode->_data;
    Node* tmpSon = tmpNode->_right;
    delete tmpNode;
    tmpNode = tmpSon;
    return;
}

template <typename T>
typename BinaryTree<T>::Node *&BinaryTree<T>::findMinNode(Node *&node){
    if(node->_left){
        return findMinNode(node->_left);
    }
    return node;
}

template <typename T>
bool BinaryTree<T>::searchNode(T data){
    return searchNodeExecution(root, data);
}

template <typename T>
bool BinaryTree<T>::searchNodeExecution(Node* node, T data){
    if(!node){
        return false;
    }
    if(data < node->_data){
        return searchNodeExecution(node->_left, data);
    } else if(data > node->_data){
        return searchNodeExecution(node->_right, data);
    } 
    return true;
}

template <typename T>
bool BinaryTree<T>::isEmpty(){
    if(root) return false; 
    return true;
}

template <typename T>
bool BinaryTree<T>::clear(){
    if(!root) return false;   
    clearExecute(root);
    return true;
}

template <typename T>
void BinaryTree<T>::clearExecute(Node *&curNode){
    if(curNode->_left){
        clearExecute(curNode->_left);
    }
    if(curNode->_right){
        clearExecute(curNode->_right);
    }
    delete curNode;
    curNode = nullptr;
}

template <typename T>
bool BinaryTree<T>::printAll(){
    if (!root) return false;
    std::cout << "arbol:" << std::endl;
    printAllExecution(root, 0);
    return true;
}

template <typename T>
void BinaryTree<T>::printAllExecution(Node* node, int curDepth){
    if(node->_right){
        printAllExecution(node->_right, curDepth + 1);
    }
     for(int i = 0; i < curDepth; i++){
            std::cout << "    ";
        }
    std::cout << node->_data << std::endl;
    if(node->_left){
        printAllExecution(node->_left, curDepth + 1);
    }
}