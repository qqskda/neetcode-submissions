class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // word1 and then word2
        string ret;
        int w1len = word1.length();
        int w2len = word2.length();

        int i = 0;
        for (i = 0; i < min(w1len, w2len); ++i)
        {
          ret.push_back(word1[i]);
          ret.push_back(word2[i]);
        }

        if (w1len == w2len) return ret;

        if (w1len > w2len)
        {
          ret.append(word1.substr(i, w1len));
        }
        else
        {
          ret.append(word2.substr(i, w2len));
        }
        return ret;

    }
};