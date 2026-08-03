#include <climits>
class Solution {
   public:
    int reverse(int x) {
        // Typical approach => append by digit;
        const int MAX_INT = pow(2, 31) - 1;
        const int MIN_INT = pow(-2, 31);
        const int upperLimit = MAX_INT / 10;
        const int lowerLimit = MIN_INT / 10;
        int ret = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (ret > upperLimit || ret < lowerLimit) return 0;
            ret *= 10;

            if (digit > 0 && ret > INT_MAX - digit) {
                return 0;
            }

            if (digit < 0 && ret < INT_MIN - digit) {
                return 0;
            }
            ret += digit;
        }
        return ret;
    }
};
