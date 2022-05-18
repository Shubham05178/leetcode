struct TrieNode{
    TrieNode* children[26]={NULL};
    bool isEnd = false;
    TrieNode(){       
        memset(children, NULL, sizeof(children));
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *curr = root;
        int len = word.size();
        for(int idx = 0; idx < len; idx++){
            if(curr->children[word[idx] - 'a'] == NULL){
                curr->children[word[idx] - 'a'] = new TrieNode();
            }
            curr = curr->children[word[idx] - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        int len = word.size();
        for(int idx = 0 ; idx< len; idx++){
            if(curr->children[word[idx] - 'a']==NULL)
                return false;
            curr = curr->children[word[idx] - 'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        int len = prefix.size();
        for(int idx = 0 ; idx< len; idx++){
            if(curr->children[prefix[idx] - 'a']==NULL)
                return false;
            curr = curr->children[prefix[idx] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */