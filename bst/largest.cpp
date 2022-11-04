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

#include<climits>

class info{
    public:
    int Max;
    int Min;
    bool isbst;
    int size;
};

info largestBSTSubtree(BinaryTreeNode<int>* root,int &ans){
    if(root==NULL){
        info res;
        res.Min = INT_MAX;
        res.Max = INT_MIN;
        res.isbst = true;
        res.size = 0;
        return res;
    }
    info left = largestBSTSubtree(root->left,ans);
    info right = largestBSTSubtree(root->right,ans);
    info curr;
    curr.size = max(left.size , right.size) + 1;
    curr.Min = min(root->data,left.Min);
    curr.Max = max(root->data,right.Max);
    
    if(left.isbst && right.isbst && (root->data>left.Max && root->data<right.Min)){
        curr.isbst = true;
        
    }
    else{
        curr.isbst = false;
    }
    if(curr.isbst){
        ans = max(ans,curr.size);
    }
    return curr;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    int largest = 0;
    info tree = largestBSTSubtree(root,largest);
    return largest;
    
}