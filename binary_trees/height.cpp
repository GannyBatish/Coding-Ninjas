/***********************************************************
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
#include<vector>
int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if(root==NULL){
        return 0;
    }
    vector<int> len;
    len.push_back(height(root->left));
    len.push_back(height(root->right));
    if(len[0]>len[1]){
        return 1+len[0];
    }
    return 1+len[1];
}