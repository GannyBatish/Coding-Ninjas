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
#include<queue>
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty()){
        BinaryTreeNode<int> *curr = pending.front();
        pending.pop();
        cout<<curr->data<<":";
        if(curr->left!=NULL){
            cout<<"L:"<<curr->left->data;
            pending.push(curr->left);
        }else{
            cout<<"L:-1";
        }
        if(curr->right!=NULL){
            cout<<",R:"<<curr->right->data;
            pending.push(curr->right);
        }else{
            cout<<",R:-1";
        }
        cout<<endl;
    }
}