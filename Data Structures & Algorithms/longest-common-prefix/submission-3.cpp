class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        // dance
        for (int i = 0; i < prefix.size(); ++i)
        {
          // dance
          char ch = prefix[i];
          for (int j = 1; j < strs.size(); ++j)
          {
            // dag danger damage
            if (i > strs[j].size() || ch != strs[j][i])
            {
              // prefix mismatch!
              prefix = prefix.substr(0, i);
            }
          }
        }
        return prefix;
    }
};