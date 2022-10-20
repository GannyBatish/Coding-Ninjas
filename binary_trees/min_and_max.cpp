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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
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