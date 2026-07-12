class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus = 1;

        for (int i = digits.size()-1; i >= 0; --i)
        {
          int digit = digits[i];
          digit += plus;
          plus = digit/10;
          digit %= 10;

          digits[i] = digit;
        }
        if (plus)
        {
          vector<int> ret;
          ret.reserve(digits.size()+1);
          ret.emplace_back(1);
          ret.insert(ret.end(), digits.begin(), digits.end());
          return ret;
        }
        else return digits;
    }
};
