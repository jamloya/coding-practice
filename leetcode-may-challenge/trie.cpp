#define index ch-'a' 

class Trie {
public:
    Trie() {}

    void insert(string word) {
        Trie* root = this;
        for (char ch : word) {
            if (!root->next[index]) { root->next[index] = new Trie(); }
            root = root->next[index];
        }
        root->isword = true;
    }

    bool search(string word) {
        Trie* root = this;
        for (char ch : word) {
            if (!root->next[index]) { return false; }
            root = root->next[index];
        }
        return root->isword;
    }

    bool startsWith(string prefix) {
        Trie* root = this;
        for (char ch : prefix) {
            if (!root->next[index]) { return false; }
            root = root->next[index];
        }
        return true;
    }

private:
    Trie* next[26] = {};
    bool isword = false;
};
