#include <iostream>
#include <queue>

#include<bits/stdc++.h>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

pair<Node<int>*,Node<int>*> construct(BinaryTreeNode<int>* root){
    Node<int> *rootNode = new Node<int>(root->data);
    pair<Node<int>*,Node<int>*> left;
    pair<Node<int>*,Node<int>*> right;
    Node<int> *head = rootNode;
    Node<int> *tail;
    if(root->left==NULL && root->right==NULL){
        pair<Node<int>*,Node<int>*> res;
        res.first = rootNode;
        res.second = rootNode;
        return res;
    }
    if(root->left!=NULL){
        left = construct(root->left);
        head = left.first;
        tail = left.second;
    }
    else{
        head = rootNode;
        tail = rootNode;
    }
    if(head!=rootNode){
        tail->next = rootNode;
        tail = tail->next;
    }
    if(root->right!=NULL){
        right = construct(root->right);
        tail->next = right.first;
        tail = right.second;
    }
    pair<Node<int>*,Node<int>*> res;
    res.first = head;
    res.second = tail;
    return res;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL){
        return NULL;
    }
    return construct(root).first;
    
}

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}