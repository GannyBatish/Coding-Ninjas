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
BinaryTreeNode<int>* buildTree(int *postorder, int *inorder, int postStart, int postEnd, int inStart, int inEnd){
    if(postStart>postEnd){
        return NULL;
    }
    int rootData = postorder[postEnd];
    int index = -1;
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i]==rootData){
            index = i;
            break;
        }
    }
    //for left subtree:
    int leftPostStart = postStart;
    int leftInStart = inStart;
    int leftInEnd = index-1;
    int leftPostEnd = leftInEnd-leftInStart+leftPostStart;
    //for right subtree:
    int rightPostStart = leftPostEnd+1;
    int rightPostEnd = postEnd-1;
    int rightInStart = index+1;
    int rightInEnd = inEnd;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTree(postorder,inorder,leftPostStart,leftPostEnd,leftInStart,leftInEnd);
    root->right = buildTree(postorder,inorder,rightPostStart,rightPostEnd,rightInStart,rightInEnd);
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return buildTree(postorder,inorder,0,postLength-1,0,inLength-1);
}