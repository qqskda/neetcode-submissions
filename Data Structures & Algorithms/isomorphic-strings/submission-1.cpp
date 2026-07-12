class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> umap;
        unordered_map<char, char> umap2;

        for (int i = 0; i < s.length(); ++i)
        {
            char cs = s[i];
            char ct = t[i];
            if (!umap.contains(cs)) umap[cs] = ct;
            if (!umap2.contains(ct)) umap2[ct] = cs;

            if (umap[cs] != ct || umap2[ct] != cs)
                return false;
        }
        return true;
    }
};