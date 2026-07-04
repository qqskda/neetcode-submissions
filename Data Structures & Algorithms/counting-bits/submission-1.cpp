class Solution {
public:
    vector<int> countBits(int n) {
        int sz = n + 1;
        vector<int> vec(sz, 0);

        for (int i = 1; i < sz; ++i)
        {
            if (i & 1)
                vec[i] = vec[i-1]+1; // n has one more one than n-1 if n is odd as bit...?
            else
                vec[i] = vec[i/2];   // n and n * 2 has same 1s if n is even as bit shifting


            // 4 = 0100 5 = 0101 6 => 0110 7 => 0111 8 => 1000 9 => 1011
        }
        return vec;
    }
};
