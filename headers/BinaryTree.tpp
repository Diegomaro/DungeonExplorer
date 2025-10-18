#include <iostream>
#include "BinaryTree.hpp"

template <typename T>
BinaryTree<T>::Node::Node(): left(nullptr), right(nullptr), subSize(1){};
template <typename T>
BinaryTree<T>::Node::Node(T data): data(data), left(nullptr), right(nullptr), subSize(1){};

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

    while(tmp->left || tmp->right){
        tmp->subSize++;
        if(tmp->data > data) {
            if(tmp->left){
                tmp = tmp->left;
            } else{
                tmp->left = newNode;
                return true;
            }
        }
        else if(tmp->data < data) {
            if(tmp->right){
                tmp = tmp->right;
            } else{
                tmp->right = newNode;
                return true;
            }
        }
        else {
            delete newNode;
            tmp = root;
            while(tmp){
                tmp->subSize--;
                if(data > tmp->data) tmp = tmp->right;
                else if(data < tmp->data) tmp = tmp->left;
                else return false;
            }
        }
    }
    tmp->subSize++;
    if(data < tmp->data){
        tmp->left = newNode;
        return true;
    } else if (data > tmp->data){
        tmp->right = newNode;
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
    if(node->data < data) {
        bool found = findNodeToDelete(node->right, data);
        if(found) node->subSize--;
        return found;
    } else if(node->data > data) {
        bool found = findNodeToDelete(node->left, data);
        if(found) node->subSize--;
        return found;
    } else{
        deleteNodeExecute(node);
        return true;
    }
    return false;
}

template <typename T>
void BinaryTree<T>::deleteNodeExecute(Node *&node){
    if(!node->left && !node->right){
        delete node;
        node = nullptr;
        return;
    }
    if(!node->left){
        Node* tmp = node->right;
        delete node;
        node = tmp;
        return;
    }
    if(!node->right){
        Node* tmp = node->left;
        delete node;
        node = tmp;
        return;
    }
    node->subSize--;
    Node *&tmpNode = findMinNode(node->right);
    if(!tmpNode->right){
        node->data = tmpNode->data;
        delete tmpNode;
        tmpNode = nullptr;
        return;
    }
    node->data = tmpNode->data;
    Node* tmpSon = tmpNode->right;
    delete tmpNode;
    tmpNode = tmpSon;
    return;
}

template <typename T>
typename BinaryTree<T>::Node *&BinaryTree<T>::findMinNode(Node *&node){
    node->subSize--;
    if(node->left){
        return findMinNode(node->left);
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
    if(data < node->data){
        return searchNodeExecution(node->left, data);
    } else if(data > node->data){
        return searchNodeExecution(node->right, data);
    } 
    return true;
}

template <typename T>
bool BinaryTree<T>::isEmpty(){
    if(root) return false; 
    return true;
}

template <typename T>
T *BinaryTree<T>::getRandomNode(){
    return &getRandomNodeExecute(root)->data;
}

template <typename T>
typename BinaryTree<T>::Node *BinaryTree<T>::getRandomNodeExecute(Node* node){
    if(!node) return nullptr;
    int x = rand() %(node->subSize);
    if(x==0){
        return node;
    }
    if(node->left && node->right){
        int k = node->left->subSize;
        int randX = rand() % (node->right->subSize + node->left->subSize);
        if(k > randX){
            return getRandomNodeExecute(node->left);
        } else{
            return getRandomNodeExecute(node->right);
        }
    }
    else if(node->left){
        return getRandomNodeExecute(node->left);
    }
    else if (node->right){
        return getRandomNodeExecute(node->right);
    }
    return nullptr;
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
    if(node->right){
        printAllExecution(node->right, curDepth + 1);
    }
     for(int i = 0; i < curDepth; i++){
            std::cout << "    ";
        }
    std::cout << node->data << std::endl;
    if(node->left){
        printAllExecution(node->left, curDepth + 1);
    }
}

template <typename T>
bool BinaryTree<T>::clear(){
    if(!root) return false;   
    clearExecute(root);
    return true;
}

template <typename T>
void BinaryTree<T>::clearExecute(Node *&curNode){
    if(curNode->left){
        clearExecute(curNode->left);
    }
    if(curNode->right){
        clearExecute(curNode->right);
    }
    delete curNode;
    curNode = nullptr;
}