class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        // String comparsion
        // Careful with string length
        // Prefix means the copmaring string must be least the same size

        int preflen = pref.length();
        int counter = 0;
        for (const string& word : words)
        {
          if (word.length() < preflen) continue;

          bool match = true;
          for (int i = 0; i < preflen; ++i)
          {
            if (pref[i] != word[i]){
              match = false;
              break;
            }
          }
          if (match) counter++;
        }
        return counter;
    }
};