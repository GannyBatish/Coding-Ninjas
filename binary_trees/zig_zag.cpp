#include <iostream>
#include <queue>

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
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return;
    }
    //R-L
    stack<BinaryTreeNode<int>*> s1;
    //L-R
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    while(!(s1.empty() && s2.empty())){
        if(s2.empty()){
            while(!s1.empty()){
                BinaryTreeNode<int>* curr = s1.top();
            	s1.pop();
            	cout<<curr->data<<" ";
                if(curr->left!=NULL){
                   s2.push(curr->left); 
                }
            	if(curr->right!=NULL){
                   s2.push(curr->right); 
                }
            	
            	if(s1.empty()){
                	cout<<endl;
            	}
            }
            
        }
        else if(s1.empty()){
            while(!s2.empty()){
                BinaryTreeNode<int>* curr = s2.top();
            	s2.pop();
            	cout<<curr->data<<" ";
                if(curr->right!=NULL){
                    s1.push(curr->right);
                }
            	if(curr->left!=NULL){
                    s1.push(curr->left);
                }
            	if(s2.empty()){
                	cout<<endl;
            	}
            }
        }
    }
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
    zigZagOrder(root);
}