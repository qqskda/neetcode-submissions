class Solution {
public:

    string encode(vector<string>& strs) {
        // Let's assume we do not know the string length for the sake of interview prep
        // So, we better use raw byte to cover int_min to int_max.

        string ret;
        for (const string& str : strs)
        {
            int sz = str.length();
            // 4 bytes int => 4 raw bytes
            ret +=  (char)(sz >> 24);
            ret += (char)(sz >> 16);
            ret += (char)(sz >> 8);
            ret += (char)(sz);
            ret += str;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;

        int i = 0;
        while (i < s.length())
        {
            int len = (int) (((unsigned char)s[i++]) << 24);
            len |= (int) (((unsigned char)s[i++]) << 16);
            len |= (int) (((unsigned char)s[i++]) << 8);
            len |= (int) (((unsigned char)s[i++]));

            ret.emplace_back(s.substr(i, len));
            i += len;
        }
        return ret;
    }
};
