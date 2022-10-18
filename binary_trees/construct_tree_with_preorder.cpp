
BinaryTreeNode<int>* helper(int *preorder, int *inorder, int preS, int preE, int inS, int inE) {
	if (inS > inE || preS > preE)
		return NULL;

	int rootData = preorder[preS];
	int index = -1;
	for (int i = inS; i <= inE; i++) {
		if (rootData == inorder[i]) {
			index = i;
			break;
		}
	}

	int linS = inS;
	int linE = index - 1;
	int lpreS = preS + 1;
	int lpreE = linE - linS + lpreS;
	int rpreS = lpreE + 1;
	int rpreE = preE;
	int rinS = index + 1;
	int rinE = inE;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = helper(preorder, inorder, lpreS, lpreE, linS, linE);
	root->right = helper(preorder, inorder, rpreS, rpreE, rinS, rinE);

	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
	// Write your code here
	return helper(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}