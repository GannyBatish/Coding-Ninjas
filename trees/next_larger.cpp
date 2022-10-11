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
#include<queue>
#include<vector>
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    if(root==NULL){
        return root;
    }
    queue<TreeNode<int>*> pending;
    vector<TreeNode<int>*> nodes;
    vector<int> diff;
    pending.push(root);
    while(!pending.empty()){
        TreeNode<int>* curr = pending.front();
        pending.pop();
        if(curr->data>x){
            nodes.push_back(curr);
            diff.push_back(curr->data-x);
        }
        for(int i=0;i<curr->children.size();i++){
            pending.push(curr->children[i]);
        }
    }
    if(nodes.empty()){
        return NULL;
    }else{
        int min=diff[0];
        int mini = 0;
        for(int i=1;i<diff.size();i++){
            if(diff[i]<min){
                min = diff[i];
                mini = i;
            }
        }
        return nodes[mini];
    }
}