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
#include<string>
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, string str){
    if(root==NULL){
        return;
    }
    str = str+to_string(root->data)+" ";
    if(root->data==k){
        if(root->right==NULL && root->left==NULL){
            cout<<str<<endl;
        }
    }
    rootToLeafPathsSumToK(root->left,k-root->data,str);
    rootToLeafPathsSumToK(root->right,k-root->data,str);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    if(root==NULL){
        return;
    }
    rootToLeafPathsSumToK(root,k,"");
}