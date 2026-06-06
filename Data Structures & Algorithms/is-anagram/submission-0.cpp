class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        sort(s.begin(), s.end(), std::less<char>());
        sort(t.begin(), t.end(), std::less<char>());

        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] != t[i])
                return false;
        }

        return true;

    }
};
