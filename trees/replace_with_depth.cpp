/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

void replaceWithDepthValue(TreeNode<int>* root,int n){
    root->data = n;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepthValue(root->children[i],n+1);
    }
}

void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return;
    }
    int n = 0;
    replaceWithDepthValue(root,n);
}