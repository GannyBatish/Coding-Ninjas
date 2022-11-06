/**********************************************************

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

void print(BinaryTreeNode<int>* root, int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    print(root->left,k-1);
    print(root->right,k-1);
}

int helper(BinaryTreeNode<int> *root, int node, int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        print(root,k);
        return 0;
    }
    int l = helper(root->left,node,k);
    if(l!=-1){
        if(l+1==k){
            cout<<root->data<<endl;
        }
        else{
            print(root->right,k-l-2);
        }
        return 1+l;
    }
    
    int r = helper(root->right,node,k);
    if(r!=-1){
        if(r+1==k){
            cout<<root->data<<endl;
        }
        else{
            print(root->left,k-r-2);
        }
        return 1+r;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    int tmp = helper(root,node,k);
}