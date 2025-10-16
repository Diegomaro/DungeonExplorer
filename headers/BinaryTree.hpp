#include "Monster.hpp"

template <typename T>
class BinaryTree{
public:
    class Node{
        public:
            T _data;
            Node *_left;
            Node* _right;
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
    bool clear();
private:
    Node* root;
    bool searchNodeExecution(Node* curNode, T data);
    void printAllExecution(Node* node, int curDepth);
    void clearExecute(Node *&node);
    bool findNodeToDelete(Node *&node, T data);
    void deleteNodeExecute(Node *&node);
    Node*& findMinNode(Node *&node);
};
#include "BinaryTree.tpp"