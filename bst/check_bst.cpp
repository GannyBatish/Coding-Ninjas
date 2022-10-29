/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<climits>
bool isBST(BinaryTreeNode<int> *root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data<=max && root->data>min){
        return isBST(root->left,min,root->data) && isBST(root->right,root->data,max);;
    }
    else{
        return false;
    }
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return isBST(root,INT_MIN,INT_MAX);
}