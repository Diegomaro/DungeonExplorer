#pragma once
#include "Monster.hpp"

template <typename T>
class BinaryTree{
public:
    class Node{
        public:
            T data;
            Node *left;
            Node* right;
            short subSize;
            Node();
            Node(T data);
        private:
    };
    BinaryTree();
    ~BinaryTree();
public:
    bool insertNode(T data);
    bool deleteNode(T data);
    bool searchNode(T data);
    bool isEmpty();
    bool printAll();
    T *getRandomNode();
    bool clear();
private:
    Node* root;
    bool findNodeToDelete(Node *&node, T data);
    void deleteNodeExecute(Node *&node);
    Node*& findMinNode(Node *&node);
    bool searchNodeExecution(Node* curNode, T data);
    Node *getRandomNodeExecute(Node *node);
    void printAllExecution(Node* node, int curDepth);
    void clearExecute(Node *&node);
};
#include "BinaryTree.tpp"