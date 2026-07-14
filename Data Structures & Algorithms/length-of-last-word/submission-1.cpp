class Solution {
public:
    int lengthOfLastWord(string s) {
        // tokenize?
        // Simply check from the back

        int start = -1, last = -1;

        for (int i = s.length()-1; i >= 0; --i)
        {
          if (s[i] != ' ' && last == -1) last = i;

          if (s[i] == ' ' && last != -1)
          {
            start = i;
            break;
          } else if (s[i] == ' ') continue;

        }
        start = max(0, start);
        return s.substr(start, max(1, (last-start))).length();
    }
};