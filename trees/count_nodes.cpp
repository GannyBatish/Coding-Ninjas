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

int getLargeNodeCount(TreeNode<int>* root, int x) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    int res = 0;
    if(root->data>x){
        res++;
    }
    for(int i=0;i<root->children.size();i++){
        res+=getLargeNodeCount(root->children[i],x);
    }
    return res;
}