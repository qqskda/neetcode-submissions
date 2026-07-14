class Solution {
public:
    int lengthOfLastWord(string s) {
        // tokenize?
        // Simply check from the back

        int ret = 0;
        for (int i = s.length()-1; i >= 0; --i)
        {
          if (s[i] == ' ' && ret != 0) return ret;
          else if (s[i] != ' ') ret++;
        }
        return ret;
    }
};