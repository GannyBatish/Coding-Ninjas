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
    pending.push(NULL);
    while(!pending.empty()){
        if(pending.size()==1 && pending.front()==NULL){
            return;
        }
        else if(pending.front()==NULL){
            cout<<endl;
            pending.push(NULL);
            pending.pop();
        }
        BinaryTreeNode<int>* curr = pending.front();
        pending.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            pending.push(curr->left);
        }
        if(curr->right!=NULL){
            pending.push(curr->right);
        }
    }
}