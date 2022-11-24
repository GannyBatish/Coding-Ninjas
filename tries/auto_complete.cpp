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
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    TrieNode *findWord(TrieNode *root, string word) {
      if (word.size() == 0) {
        return root;
      }
      if (root->children[word[0] - 'a'] == NULL) {
        return NULL;
      }
      return findWord(root->children[word[0] - 'a'], word.substr(1));
    }

    void printAllPossibleWords(TrieNode *root, string word) {
      if (root->isTerminal) {
        cout << word << endl;
      }
      for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
          char ch = i + 'a';
          printAllPossibleWords(root->children[i], word + ch);
        }
      }
    }

    void autoComplete(TrieNode *root,string pattern){
        
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i=0;i<input.size();i++){
            insertWord(input[i]);
        }
        TrieNode *base = findWord(root, pattern);
        if (base == NULL)
        {
            return;
        }
        string word = pattern;
        printAllPossibleWords(base, word);
    }
};