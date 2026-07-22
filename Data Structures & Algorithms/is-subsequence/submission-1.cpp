class Solution {
public:
    bool isSubsequence(string s, string t) {
        // if s is subsequent of t
        // Simply check if t has all s characters in order
        if (s == "") return true;
        
        int si = 0;

        for (const char ch : t)
        {
          if (s[si] == ch)
          {
            ++si;
            if (si == s.length()) return true;
          }
        }
        return false;
    }
};