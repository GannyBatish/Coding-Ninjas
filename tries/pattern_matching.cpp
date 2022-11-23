#include <string>
#include <vector>

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1)) && insertWord(this->root,word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    bool searchPattern(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }
        if (root->children[word[0] - 'a'] == NULL)
        {
            return false;
        }
        return searchPattern(root->children[word[0] - 'a'], word.substr(1));
    }

    bool searchPattern(string word)
    {
        return searchPattern(root, word);
    }

    bool patternMatching(vector<string> vect, string pattern)
    {
        for (int i = 0; i < vect.size(); i++)
        {
            string word = vect[i];
            for (int j = 0; j < word.size(); j++)
            {
                insertWord(word.substr(j));
            }
        }
        return searchPattern(pattern);
    }

/*
    bool patternMatching(TrieNode *root,string pattern){
        int index = pattern[0] - 'a';
        if (pattern.size() == 0) {
          return true;
        }
        if (root->children[index] == NULL) {
            return false;
        }
        
        TrieNode* child = root->children[index];
        return patternMatching(child,pattern.substr(1));
    }

    bool patternMatching(vector<string> vect, string pattern) {
        // Write your code here
        for(int i=0;i<vect.size();i++){
            insertWord(vect[i]);
        }
        return patternMatching(root, pattern);
    }*/
};