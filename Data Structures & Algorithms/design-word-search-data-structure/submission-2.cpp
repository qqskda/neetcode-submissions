class WordDictionary {
    bool isWord = false;
    WordDictionary* children[26] = {};
public:
    WordDictionary() = default;
    
    void addWord(string word) {
        if (word.empty()) return;

        char ch = word.front();
        int index = ch-'a';

        if (children[index] == nullptr)
            children[index] = new WordDictionary();
        
        if (word.size() == 1)
        {
            children[index]->isWord = true;
            return;
        }
        children[index]->addWord(word.substr(1));
    }
    
    bool search(string word) {
        if (word.empty()) return false;

        char ch = word.front();
        bool isDot = (ch == '.');
        int sz = word.size();
        string sstr = word.substr(1);

        if (!isDot)
        {
            if (children[ch-'a'] == nullptr) return false;

            if (sz == 1) return children[ch-'a']->isWord;

            return children[ch-'a']->search(sstr);
        }
        // isDot
        if (sz == 1)
        {
            for (int i = 0; i < 26; ++i)
            {
                if(children[i] && children[i]->isWord) return true;
            }
            return false;
        }
        
        for (int i = 0; i < 26; ++i)
        {
            if(children[i] && children[i]->search(sstr)) return true;
        }
        return false;
    }
};
