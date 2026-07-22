class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // max binary odd number: ends with ...1

        // 1. Check how many 1s
        // 2. Put 1 at the end, rest goes to the front


        int ones = 0;

        for (const char ch : s)
        {
            if (ch == '1') ++ones;
        }

        int zeros = s.length() - ones;
        string ret(ones-1, '1');
        
        while (zeros--) ret.append("0");
        ret.append("1");
        return ret;
    }
};