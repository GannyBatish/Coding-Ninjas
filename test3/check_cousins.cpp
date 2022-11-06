// Following is the Binary Tree node structure
/**************
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
***************/
#include<queue>
#include<vector>
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    queue<BinaryTreeNode<int>*> pending;
    vector<vector<int>> nodes;
    if(root!=NULL){
        pending.push(root);
        pending.push(NULL);
    }
    while(!pending.empty()){
        if(pending.size()==1 && pending.front()==NULL){
            pending.pop();
            break;
        }
        if(pending.front()==NULL){
            pending.pop();
            pending.push(NULL);
        }
        else{
        	vector<int> currLevel;
        	BinaryTreeNode<int>* curr = pending.front();
        	while(curr){
            	currLevel.push_back(curr->data);
            	if(curr->left){
                	pending.push(curr->left);
            	}
            	if(curr->right){
             		pending.push(curr->right);
            	}
                pending.pop();
                curr = pending.front();
        	}
            nodes.push_back(currLevel);
    	}
    }
    if(nodes.size()>=1 && root!=NULL){
        bool found = false;
        for(int i=0;i<nodes.size();i++){
            bool found1 = false;
            bool found2 = false;
            for(int j=0;j<nodes[i].size();j++){
                if(nodes[i][j]==p){
                    found1 = true;
                }
                if(nodes[i][j]==q){
                    found2 = true;
                }
            }
            found = found || (found1 && found2);
        }
        return found;
    }
}
