/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

#include<stack>

int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

void completeLeft(BinaryTreeNode<int> *root,stack<BinaryTreeNode<int>*> &s){
    if(root==NULL){
        return;
    }
    s.push(root);
    completeLeft(root->left,s);
}

void completeRight(BinaryTreeNode<int> *root, stack<BinaryTreeNode<int>*> &s){
    if(root==NULL){
        return;
    }
    s.push(root);
    completeRight(root->right,s);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if(root==NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> inorder;
    stack<BinaryTreeNode<int>*> revInorder;
    int n = countNodes(root);
    completeLeft(root,inorder);
    completeRight(root,revInorder);
    for(int i=0;i<n;i++){
        BinaryTreeNode<int> *a = inorder.top();
        BinaryTreeNode<int> *b = revInorder.top();
        int sum =  a->data + b->data;
        if(sum==s && a->data<b->data){
            BinaryTreeNode<int> *intmp = inorder.top();
            inorder.pop();
            BinaryTreeNode<int> *revtmp = revInorder.top();
            revInorder.pop();
            cout<<intmp->data<<" "<<revtmp->data<<endl;
            completeLeft(intmp->right,inorder);
            completeRight(revtmp->left,revInorder);
        }
        else if(sum>s){
            BinaryTreeNode<int> *tmp = revInorder.top();
            revInorder.pop();
            completeRight(tmp->left,revInorder);
        }
        else if(sum<s){
            BinaryTreeNode<int> *tmp = inorder.top();
            inorder.pop();
            completeLeft(tmp->right,inorder);
        }
    }
}