#include<iostream>
#include<queue>
#include "treeNode.h"
using namespace std;

treeNode<int>* takeInputLevel(){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    treeNode<int> *root = new treeNode<int>(data);
    queue<treeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0){
        treeNode<int>* curr = pending.front();
        pending.pop();
        int n;
        cout<<"Enter number of children for "<<curr->data<<" : ";
        cin>>n;
        for(int i=0;i<n;i++){
            int c;
            cout<<"Enter child "<<i<<" of "<<curr->data<<" : ";
            cin>>c;
            treeNode<int>* child = new treeNode<int>(c);
            curr->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}

treeNode<int>* takeInput(){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    treeNode<int> *root = new treeNode<int>(data);
    int n;
    cout<<"Enter no of children: ";
    cin>>n;
    for(int i=0;i<n;i++){
        treeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(treeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]<<" ";
    }
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int numNodes(treeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int res = 1;
    for(int i=0;i<root->children.size();i++){
        res+=numNodes(root->children[i]);
    }
    return res;
}

void printAtLevel(treeNode<int> *root,int n){
    if(root==NULL){
        return;
    }
    if(n==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printAtLevel(root->children[i],n-1);
    }
}

void preorder(treeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

int main(){
    treeNode<int>* root = new treeNode<int>(1);
    treeNode<int>* n1 = new treeNode<int>(2);
    treeNode<int>* n2 = new treeNode<int>(3);
    root->children.push_back(n1);
    root->children.push_back(n2);
    return 0;
}