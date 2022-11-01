#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
// my code start *******************************************************************
#include<stack>

int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

void completeLeft(BinaryTreeNode<int> *root,stack<BinaryTreeNode<int>*> &s){
    if(root==NULL){
        return;
    }
    s.push(root);
    completeLeft(root->left,s);
}

void completeRight(BinaryTreeNode<int> *root, stack<BinaryTreeNode<int>*> &s){
    if(root==NULL){
        return;
    }
    s.push(root);
    completeRight(root->right,s);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if(root==NULL){
        return;
    }
    // create two stacks to store inorder traversal and reverse inorder traversal simultaneously
    stack<BinaryTreeNode<int>*> inorder;
    stack<BinaryTreeNode<int>*> revInorder;
    // get total nodes 
    int n = countNodes(root);
    completeLeft(root,inorder);
    completeRight(root,revInorder);
    // repeat for n times (prevent infinite loop)
    for(int i=0;i<n;i++){
        BinaryTreeNode<int> *a = inorder.top();
        BinaryTreeNode<int> *b = revInorder.top();
        int sum =  a->data + b->data;
        if(sum==s && a->data<b->data){
            BinaryTreeNode<int> *intmp = inorder.top();
            inorder.pop();
            BinaryTreeNode<int> *revtmp = revInorder.top();
            revInorder.pop();
            cout<<intmp->data<<" "<<revtmp->data<<endl;
            completeLeft(intmp->right,inorder);
            completeRight(revtmp->left,revInorder);
        }
        else if(sum>s){
            BinaryTreeNode<int> *tmp = revInorder.top();
            revInorder.pop();
            completeRight(tmp->left,revInorder);
        }
        else if(sum<s){
            BinaryTreeNode<int> *tmp = inorder.top();
            inorder.pop();
            completeLeft(tmp->right,inorder);
        }
    }
}
// my code ends *************************************************************

BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}