#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
using namespace std;

void printTree(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<" L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<" R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput(){
    int n;
    cout<<"Data: ";
    cin>>n;
    if(n==-1){
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(n);
    BinaryTreeNode<int> * l = takeInput();
    BinaryTreeNode<int> * r = takeInput();
    root->left = l;
    root->right = r;
    return root;
}

BinaryTreeNode<int>* takeInputLevel(){
    int n;
    cout<<"Root Data: ";
    cin>>n;
    if(n==-1){
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(n);
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty()){
        BinaryTreeNode<int>* curr = pending.front();
        pending.pop();
        cout<<"Left Data of "<<curr->data;
        int l;
        cin>>l;
        if(l!=-1){
            curr->left = new BinaryTreeNode<int>(l);
            pending.push(curr->left);
        }
        cout<<"Right Data of "<<curr->data;
        int r;
        cin>>r;
        if(r!=-1){
            curr->right = new BinaryTreeNode<int>(r);
            pending.push(curr->right);
        }
    }
    return root;
}

int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

void inorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

pair<int,int> heightDiameter(BinaryTreeNode<int> *root){
    if(root==NULL){
        return pair<int,int>(0,0);
    }
    // pair<height,diameter>
    pair<int,int> left = heightDiameter(root->left);
    pair<int,int> right = heightDiameter(root->right);
    int height = 1 + max(left.first,right.first);
    int diameter = max(height,max(left.second,right.second));
    return pair<int,int>(height,diameter);
}

int main(){

}