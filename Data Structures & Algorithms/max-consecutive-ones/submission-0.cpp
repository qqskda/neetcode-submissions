class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = INT_MIN;
        int curr = 0;
        for (const int& num : nums)
        {
          if (num == 1) curr++;
          else
          {
            ret = max(ret, curr);
            curr = 0;
          }
        }
        return max(ret, curr);
    }
};