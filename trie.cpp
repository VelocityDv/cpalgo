// world list validation trie is useful


// e.g. finding words in a crossword
// e.g. finding celebrity names in a sentence / text


// trie also used for if invalid word or not when in text editors use underline
// auto complete or spell complete.


class TrieNode{
public:
    map<char, TrieNode*> children;
    bool terminates;

    char data;

    TrieNode(char c) : data(c), terminates(false) {}


};

class Trie {
public:
    TrieNode* root; 

    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        if(word.empty())
            return;
        
        TrieNode* current = root;
        for(auto c : word){
            //cannot find it then we insert.
            if(current->children.find(c) == current->children.end()){
                current->children[c] = new TrieNode(c);
            }
            current = current->children[c];
        }
        current->terminates = true;
    }
    
    bool search(string word) {
        
        TrieNode* current = root;
        for(auto c : word){
            if(current->children.find(c) != current->children.end()){
                current = current->children[c];
            }
            else{
                return false;
            }
        }
        return current->terminates;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for(auto c : prefix){
            if(current->children.find(c) != current->children.end()){
                current = current->children[c];
            }
            else{
                return false;
            }
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