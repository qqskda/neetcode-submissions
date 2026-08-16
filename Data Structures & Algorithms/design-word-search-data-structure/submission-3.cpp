class WordDictionary {
    bool isWord = false;
    WordDictionary* children[26] = {};

    bool search(const string& word, int pos)
    {
        if (pos == word.size()) return isWord;

        char ch = word[pos];

        if (ch != '.')
        {
            int index = ch-'a';

            if (!children[index]) return false;

            return children[index]->search(word, pos+1);
        }

        for (int i = 0; i < 26; ++i)
        {
            if (children[i] && children[i]->search(word, pos+1)) return true;
        }
        return false;
    }
public:
    WordDictionary() = default;
    
    void addWord(string word) {
        WordDictionary* node = this;

        for (char ch : word)
        {
            int index = ch - 'a';
            if (!node->children[index])
                node->children[index] = new WordDictionary();
            node = node->children[index];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return search(word, 0);
    };
};
