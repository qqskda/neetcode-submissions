class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        // String comparsion
        // Careful with string length
        // Prefix means the copmaring string must be least the same size

        int counter = 0;
        int preflen = pref.length();
        for (const string& word : words)
        {
          if (word.length() < preflen) continue;
          if (word.rfind(pref, 0) == 0) counter++;
        }
        return counter;
    }
};