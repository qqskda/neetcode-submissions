class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 2^x = n 
        // 2^(x-1) * 2 = n
        // 2^(x-1) = n / 2
        // if N == 2^x, n/2 should be even

        if (n <= 0) return false;
        while (n > 1)
        {
          if (n%2 == 1) return false;
          n = n / 2;
        }
        return true;
    }
};