class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

    string reverseWord(string word) {
      string reverse = "";
      for (int i = word.size() - 1; i >= 0; i--) {
        reverse += word[i];
      }
      return reverse;
    }

    bool isPalindromePair(TrieNode *root, vector<string> words) {
      if (words.size() == 0) {
        return false;
      }

      for (int i = 0; i < words.size(); i++) {
        if (doesPairExistFor(root, words[i], 0)) {
          return true;
        }
      }
      return false;
    }

    bool doesPairExistFor(TrieNode *root, string word, int startIndex) {
      if (word.size() == 0) {
        return true;
      }

      if (startIndex == word.length()) {
        if (root->isTerminal) {
          return true;
        }
        string wrd = "";
        wrd += root->data;
        return checkRemainingBranchesInTries(root, wrd);
      }
      int charIndex = word[startIndex] - 'a';
      TrieNode *child = root->children[charIndex];

      if (child == NULL) {
        if (root->isTerminal) {
          return checkWordForPalindrome(word.substr(startIndex));
        }
        return false;
      }

      return doesPairExistFor(child, word, startIndex + 1);
    }

    bool checkRemainingBranchesInTries(TrieNode *root, string word) {
      if (root->isTerminal) {
        if (checkWordForPalindrome(word)) {
          return true;
        }
      }

      for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
          char ch = i + 'a';
          if (checkRemainingBranchesInTries(root->children[i], word + ch)) {
            return true;
          }
        }
      }

      return true;
    }

    bool checkWordForPalindrome(string word) {
      int start = 0;
      int end = word.size() - 1;

      while (start < end) {
        if (word[start] != word[end]) {
          return false;
        }
        start++;
        end--;
      }
      return true;
    }

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for (int i = 0; i < words.size(); i++) {
            add(reverseWord(words[i]));
        }

        return isPalindromePair(root, words);
    }
};