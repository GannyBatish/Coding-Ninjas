/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
#include<bits/stdc++.h>
#include<climits>
#include<queue>

class BST {
    // Define the data members
    BinaryTreeNode<int> *root;
   public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }
	pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    pair<int,int> curr = pair<int,int>(INT_MAX,0);
    if(root==NULL){
        return curr;
    }
    pair<int,int> left = getMinAndMax(root->left);
    pair<int,int> right = getMinAndMax(root->right);
    int Min = min(root->data,min(left.first,right.first));
    int Max = max(root->data,max(left.second,right.second));
    return pair<int,int>(Min,Max);
	}
	/*----------------- Public Functions of BST -----------------*/
    private:
    bool hasData(BinaryTreeNode<int> *node,int data){
        if(node==NULL){
            return false;
        }
        if(node->data==data){
            return true;
        }
        if(data<node->data){
            return hasData(node->left,data);
        }
        if(data>node->data){
            return hasData(node->right,data);
        }
    }
    public:
    bool hasData(int data){
        return hasData(root,data);
    }

    private:
    BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>* node,int data){
        if(node==NULL){
            return NULL;
        }
        if(data>node->data){
            node->right = deleteData(node->right,data);
            return node;
        }
        if(data<node->data){
            node->left = deleteData(node->left,data);
            return node;
        }
        if(data==node->data){
            if(node->left==NULL && node->right==NULL){
                return NULL;
            }
            if(node->right==NULL){
                return node->left;
            }
            if(node->left==NULL){
                return node->right;
            }
            else{
                pair<int,int> minMax = getMinAndMax(root->right);
                int min = minMax.first;
                node->data = min;
                node->right = deleteData(node->right,min);
                return node;
            }
        }
    }
    public:
    void remove(int data) { 
        // Implement the remove() function 
        if(!hasData(data)){
            return;
        }
        this->root = deleteData(this->root,data);
    }

     void print(BinaryTreeNode<int>*root){
            if(root==NULL){
                return;
            }
            cout<<root->data<<":";
            if(root->left!=NULL){
                cout<<"L:"<<root->left->data<<",";
            }
            if(root->right!=NULL){
                cout<<"R:"<<root->right->data;
            }
            cout<<"\n";
            print(root->left);
            print(root->right);
        }
        void print() { 
            print(root);
        }
    

    
    
    private:
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node,int data){
        if(node==NULL){
            return new BinaryTreeNode<int>(data);
        }
        if(data>node->data){
            node->right = insert(node->right,data);
        }
        if(data<=node->data){
            node->left = insert(node->left,data);
        }
        return node;
    }
    public:
    void insert(int data) { 
        // Implement the insert() function 
        this->root =  insert(root,data);
    }

    bool search(int data) {
		// Implement the search() function
        return hasData(data);
    }
};