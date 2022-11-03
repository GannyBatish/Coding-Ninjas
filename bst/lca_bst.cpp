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

int getLCA(BinaryTreeNode<int>* root , int n1 , int n2){
    // Write your code here
    if(root==NULL){
        return -1;
    }
    if(root->data==n1 || root->data==n2){
        return root->data;
    }
    if((root->data>n1 && root->data<n2)||(root->data<n1 && root->data>n2)){
        return root->data;
    }
    int res = -1;
    if(root->data<n1 && root->data<n2){
        res = getLCA(root->right,n1,n2);
    }
    else if(root->data>n1 && root->data>n2){
        res = getLCA(root->left,n1,n2);
    }
    return res;
}