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
int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    int sum = root->data;
    sum+=getSum(root->left);
    sum+=getSum(root->right);
    return sum;
}

int replace(BinaryTreeNode<int>* root,int greater){
    if(root==NULL){
        return 0;
    }
    int r = replace(root->right,greater);
    root->data = root->data+max(r,greater);
    int l = replace(root->left,root->data);
    return max(l,root->data);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return;
    }
    int tmp = replace(root,0);
}