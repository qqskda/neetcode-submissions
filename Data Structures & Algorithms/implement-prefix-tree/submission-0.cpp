class PrefixTree {
    bool _isWord;
    PrefixTree* _alphabets[26];
public:
    PrefixTree() {
        _isWord = false;
        for (int i = 0; i < 26; ++i)
            _alphabets[i] = nullptr;
    }
    
    void insert(string word) {
        if (word.empty()) return;

        int sz = word.length();
        char ch = word.front();
        int index = ch - 'a';

        if (_alphabets[index] == nullptr)
            _alphabets[index] = new PrefixTree();
        
        if (sz == 1) _alphabets[index]->_isWord = true;
        _alphabets[index]->insert(word.substr(1));
    }
    
    bool search(string word) {
        if (word.empty()) return false;

        int sz = word.length();
        char ch = word.front();
        int index = ch - 'a';

        if (_alphabets[index] == nullptr) return false;
        if (sz == 1) return _alphabets[index]->_isWord;

        return _alphabets[index]->search(word.substr(1));
    }
    
    bool startsWith(string prefix) {
        if (prefix.empty()) return false;

        int sz = prefix.length();
        char ch = prefix.front();
        int index = ch - 'a';

        if (_alphabets[index] == nullptr) return false;
        if (sz == 1) return true;

        return _alphabets[index]->startsWith(prefix.substr(1));
    }
};
