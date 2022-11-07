// Following is the Binary Tree node structure
/**************
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
***************/

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root == NULL) return NULL;
    if(!root->left && !root->right){
        vector<int> *ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    vector<int> *left = longestPath(root->left);
    vector<int> *right = longestPath(root->right);
    if(!left){
    	right->push_back(root->data);
        return right;
    }
    else if(!right){
        left->push_back(root->data);
        return left;
    }else{
        if(left->size() > right->size()){
            left->push_back(root->data);
            delete right;
            return left;
        }else{
            right->push_back(root->data);
            delete left;
            return right;
        }
    }
}