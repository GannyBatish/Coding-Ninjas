#include "trieNode.h"

class trie{
    private:
    trieNode *root;

    public:

    trie(){
        root = new trieNode('\0');
    }

    void insert(trieNode* root, string input){
        if(input.size()==0){
            root->isTerminal = true;
            return;
        }
        int index = input[0]-'a';
        trieNode *child;
        if(root->children[index]!=NULL){
            child = children[index];
        }
        else{
            child = new trieNode(input[0]);
            root->children[index] = child;
        }

        insert(child,input.substr(1));
    }

    void insert(string input){
        insert(this->root,input);
    }

    bool search(TrieNode *root, string word){
        if(word.size()==0 && root->isTerminal){
            return true;
        }
        if(word.size()==0 && !root->isTerminal){
            return false;
        }
        int index = word[0]-'a';
        if(root->children[index]==NULL){
            return false;
        }
        TrieNode *child = root->children[index];
        return search(child,word.substr(1));
    }

    bool search(string word) {
        // Write your code here
        return search(root,word);
    }


    void remove(trieNode *root,string word){
        if(word.size()==0){
            root->isTerminal = false;
            return;
        }

        trieNode *child;
        int index = word[0]-'a';
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return;
        }
        remove(child,word.substr(1));

        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL; 
        }
    }

    void remove(string word){
        remove(root,word);
    }
}