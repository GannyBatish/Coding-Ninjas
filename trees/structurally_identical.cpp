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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if(root1==NULL || root2==NULL || root1->data!=root2->data){
        return false;
    }
    int n = root1->children.size();
    int n2 = root2->children.size();
    bool res = true;
    if(n==n2){
        for(int i=0;i<n;i++){
            res = res&&areIdentical(root1->children[i],root2->children[i]);
        }
    }
    else{
        res = false;
    }
    return res;
}