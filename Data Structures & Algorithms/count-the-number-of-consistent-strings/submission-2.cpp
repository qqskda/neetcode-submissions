class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ret = 0;
        std::array<int, 27> arr = {0};
        //int arr[27] = {};

        for (const char ch : allowed)
        {
          arr[ch-'a'] = 1;
        }
        for (const string& word : words)
        {
          ++ret;
          for (const char ch : word)
          {
            if (arr[ch-'a'] == 0)
            {
              --ret;
              break;
            }
          }
        }
        return ret;
    }
};