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
};

using namespace std;
BinaryTreeNode<int>* buildTree(int *postorder, int *inorder, int postStart, int postEnd, int inStart, int inEnd){
    if(postStart>postEnd){
        return NULL;
    }
    int rootData = postorder[postEnd];
    int index = -1;
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i]==rootData){
            index = i;
            break;
        }
    }
    //for left subtree:
    int leftPostStart = postStart;
    int leftInStart = inStart;
    int leftInEnd = index-1;
    int leftPostEnd = leftInEnd-leftInStart+leftPostStart;
    //for right subtree:
    int rightPostStart = leftPostEnd+1;
    int rightPostEnd = postEnd-1;
    int rightInStart = index+1;
    int rightInEnd = inEnd;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTree(postorder,inorder,leftPostStart,leftPostEnd,leftInStart,leftInEnd);
    root->right = buildTree(postorder,inorder,rightPostStart,rightPostEnd,rightInStart,rightInEnd);
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return buildTree(postorder,inorder,0,postLength-1,0,inLength-1);
}

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
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}