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
#include<queue>

int sum(TreeNode<int>* root){
    int res = root->data;
    for(int i=0;i<root->children.size();i++){
        res+=root->children[i]->data;
    }
    return res;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL || root->children.size()==0){
        return root;
    }
    vector<int> sums;
    vector<TreeNode<int>*> nodes;
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty()){
        TreeNode<int>* curr = pending.front();
        pending.pop();
        sums.push_back(sum(curr));
        nodes.push_back(curr);
        for(int i=0;i<curr->children.size();i++){
            pending.push(curr->children[i]);
        }
    }
    
    int max=0;
    int maxi = 0;
    for(int i=0;i<sums.size();i++){
        if(sums[i]>max){
            max = sums[i];
            maxi = i;
        }
    }
    return nodes[maxi];
}