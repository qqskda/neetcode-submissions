class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int arr[26] = {};
        for (char ch : s) arr[ch - 'a']++;

        for (char ch : t) {
            arr[ch - 'a']--;
            if (arr[ch - 'a'] < 0) return false;
        }

        for (int i = 0; i < 26; ++i) {
            if (arr[i]) return false;
        }

        return true;
    }
};
