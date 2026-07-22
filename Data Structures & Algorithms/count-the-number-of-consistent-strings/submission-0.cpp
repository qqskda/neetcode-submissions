class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ret = 0;

        for (const string& word : words)
        {
          ++ret;
          for (const char ch : word)
          {
            if (!allowed.contains(ch))
            {
              --ret;
              break;
            }
          }
        }
        return ret;
    }
};