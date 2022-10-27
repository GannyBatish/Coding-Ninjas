#include"binaryTreeNode.h"
#include<bits/stdc++.h>
#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    pair<int,int> curr = pair<int,int>(INT_MAX,0);
    if(root==NULL){
        return curr;
    }
    pair<int,int> left = getMinAndMax(root->left);
    pair<int,int> right = getMinAndMax(root->right);
    int Min = min(root->data,min(left.first,right.first));
    int Max = max(root->data,max(left.second,right.second));
    return pair<int,int>(Min,Max);
}

class bst{
    BinaryTreeNode<int>* root;

    public:
    bst(){
        root = NULL;
    }
    ~bst(){
        delete root;
    }

    private:
    bool hasData(BinaryTreeNode<int> *node,int data){
        if(node==NULL){
            return false;
        }
        if(node->data==data){
            return true;
        }
        if(data<node->data){
            return hasData(node->left,data);
        }
        if(data>node->data){
            return hasData(node->right,data);
        }
    }
    public:
    bool hasData(int data){
        return hasData(root,data);
    }
    private:
    BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>* node,int data){
        if(node==NULL){
            return NULL;
        }
        if(data>node->data){
            node->right = deleteData(node->right,data);
        }
        if(data<node->data){
            node->left = deleteData(node->left,data);
        }
        if(data==node->data){
            if(node->left==NULL && node->right==NULL){
                return NULL;
            }
            if(node->right==NULL){
                return node->left;
            }
            if(node->left==NULL){
                return node->right;
            }
            else{
                pair<int,int> minMax = getMinAndMax(root->right);
                int min = minMax.first;
                node->data = min;
                node->right = deleteData(node->right,min);
                return node;
            }
        }
    }
    public:
    void deleteData(int data){
        if(!hasData(data)){
            return;
        }
        this->root = deleteData(this->root,data);
    }
    private:
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node,int data){
        if(node==NULL){
            return new BinaryTreeNode<int>(data);
        }
        if(data>node->data){
            node->right = insert(node->right,data);
        }
        if(data<node->data){
            node->left = insert(node->right,data);
        }
        return node;
    }
    public:
    void insert(int data){
        this->root =  insert(root,data);
    }
};

/*
class BST
{
    BinaryTreeNode<int> *root;

    bool hasDataHelper(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return hasDataHelper(root->left, data);
        }
        else
        {
            return hasDataHelper(root->right, data);
        }
    }

    BinaryTreeNode<int> *insertDataHelper(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data <= root->data)
        {
            root->left = insertDataHelper(root->left, data);
        }
        else
        {
            root->right = insertDataHelper(root->right, data);
        }
        return root;
    }

    BinaryTreeNode<int> *deleteDataHelper(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (data > root->data)
        {
            root->right = deleteDataHelper(root->right, data);
            return root;
        }
        else if (data < root->data)
        {
            root->left = deleteDataHelper(root->left, data);
            return root;
        }
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (!root->left && root->right)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (!root->right && root->left)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = root->right;

                while (minNode->left)
                {
                    minNode = minNode->left;
                }
                int right_min = minNode->data;
                root->data = right_min;
                root->right = deleteDataHelper(root->right, right_min);
                return root;
            }
        }
    }

    void printTreeHelper(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTreeHelper(root->left);
        printTreeHelper(root->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    void remove(int data)
    {
        this->root = deleteDataHelper(this->root, data);
    }

    void print()
    {
        printTreeHelper(this->root);
    }

    void insert(int data)
    {
        this->root = insertDataHelper(this->root, data);
    }

    bool search(int data)
    {
        return hasDataHelper(root, data);
    }
};
*/


int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}