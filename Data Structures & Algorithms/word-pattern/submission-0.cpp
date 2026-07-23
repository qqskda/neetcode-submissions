class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        stringstream ss(s);
        string word;
        int i = 0;

        while (ss >> word)
        {
            if (i >= pattern.size()) return false;

            char ch = pattern[i];

            if (charToWord.count(ch) && charToWord[ch] != word) return false;

            if (wordToChar.count(word) && wordToChar[word] != ch) return false;

            charToWord[ch] = word;
            wordToChar[word] = ch;
            ++i;
        }
        return i == pattern.size();
    }
};