class Solution {
public:
    vector<int> countBits(int n) {
        int sz = n + 1;
        vector<int> vec(sz, 0);

        for (int i = 0; i < sz; ++i)
        {
            int num = i;
            int ones = 0;
            while (num > 0)
            {
                int bit = num & 1;
                if (bit == 1) ones++;
                num = num >> 1;
            }
            vec[i] = ones;
        }
        return vec;
    }
};
