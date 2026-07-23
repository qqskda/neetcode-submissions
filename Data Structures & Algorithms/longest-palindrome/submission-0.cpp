class Solution {
public:
    int longestPalindrome(string s) {
        // Even length: left and right shoul be always match hence all char should be 2*n
        // Odd length: left and right should be match, and middle can be anything => char 2*n and one char can be odd*n

        // put all the char to a map
        // if there is one odd, add rest skip
        // add all the even num
        unordered_map<char,int>umap;
        for (const char ch : s) umap[ch]++;

        int length = 0;
        bool hasOdd = false;
        for (auto itr : umap)
        {
            if (itr.second % 2 == 0) length += itr.second;
            else
            {
                hasOdd = true;
                length += itr.second - 1;
            }
        }

        if (hasOdd) length += 1;
        return length;
    }
};