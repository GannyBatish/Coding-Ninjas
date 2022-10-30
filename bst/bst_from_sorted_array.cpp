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

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    if(n==0){
        cout<<"returning null"<<endl;
        return NULL;
    }
    if(n==1){
        cout<<"returning "<<input[0]<<endl;
        return new BinaryTreeNode<int>(input[0]);
    }
    int mid = n/2;
    cout<<"Mid: "<<mid<<endl;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    int arr[n];
    int s = 0;
    for(int i=0;i<mid;i++){
        arr[i] = input[i];
        s++;
    }
    root->left = constructTree(arr,s);
    s = 0;
    int k = mid+1;
    cout<<"k: "<<k<<endl;
    for(int i=0;i<n;i++){
        arr[i] = input[k++];
        s++;
    }
    root->right = constructTree(arr,s);
    return root;
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

void preOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}