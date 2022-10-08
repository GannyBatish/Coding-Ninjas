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
#include<vector>
int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    int res = 1;
    vector<int> depths;
    for(int i=0;i<root->children.size();i++){
        depths.push_back(getHeight(root->children[i]));
    }
    int max = 0;
    for(int i=0;i<depths.size();i++){
        if(depths[i]>max){
            max = depths[i];
        }
    }
    return res+max;
}