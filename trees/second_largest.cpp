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
#include<limits>
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return root;
    }
    queue<TreeNode<int>*> pending;
    vector<TreeNode<int>*> nodes;
    pending.push(root);
    while(!pending.empty()){
        TreeNode<int>* curr = pending.front();
        pending.pop();
        nodes.push_back(curr);
        for(int i=0;i<curr->children.size();i++){
            pending.push(curr->children[i]);
        }
    }
    if(nodes.size()<2){
        return NULL;
    }
    TreeNode<int>* largest=new TreeNode<int>(INT_MIN);
    TreeNode<int>* largest2 = new TreeNode<int>(INT_MIN);
    for(int i=0;i<nodes.size();i++){
        if(nodes[i]->data>largest->data){
            largest2 = largest;
            largest = nodes[i];
        }
        else if(nodes[i]->data>largest2->data && nodes[i]->data!=largest->data){
            largest2 = nodes[i];
        }
    }
    return largest2;
}