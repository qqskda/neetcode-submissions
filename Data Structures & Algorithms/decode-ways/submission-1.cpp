class Solution {
public:
    int decode(const string& s, const int index, vector<int>& dp)
    {
        if (index == s.size()) return 1;

        // Cannot start with 0
        if (s[index] == '0') return 0;

        // check dp
        if (dp[index] != -1) return dp[index];

        // get the ways of when consuming one digit from my index
        int ways = decode(s, index+1, dp);

        if (index+1 < s.size())
        {
            int value = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if (value >= 10 && value <= 26)
                ways += decode(s, index + 2, dp);  // get the ways of when consuming two digits from my index
        }
        dp[index] = ways;
        return ways;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return decode(s, 0, dp);        
    }
};
