class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 9 9 9 9 
        // 1 0 0 0 0
        for (int i = digits.size()-1; i >= 0; --i)
        {
          if (digits[i] != 9)
          {
            digits[i]++;
            return digits;
          }
          digits[i] = 0;
        }
        digits.emplace_back(0);
        digits[0] = 1;
        return digits;
    }
};
