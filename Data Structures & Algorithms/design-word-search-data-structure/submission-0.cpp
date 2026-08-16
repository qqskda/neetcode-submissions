class WordDictionary {
    bool isWord;
    WordDictionary* children[26];
public:
    WordDictionary() {
        isWord = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
    
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

        if (!isDot && children[ch-'a'] == nullptr) return false;

        // last char
        if (sz == 1 && !isDot)
        {
            return children[ch-'a']->isWord;
        }

        if (sz == 1 && isDot)
        {
            for (int i = 0; i < 26; ++i)
            {
                if(children[i] && children[i]->isWord) return true;
            }
            return false;
        }
        
        // Not last char
        string sstr = word.substr(1);

        if (!isDot)
        {
            return children[ch-'a']->search(sstr);
        }

        // isDot
        for (int i = 0; i < 26; ++i)
        {
            if(children[i] && children[i]->search(sstr)) return true;
        }
        return false;
    }
};
