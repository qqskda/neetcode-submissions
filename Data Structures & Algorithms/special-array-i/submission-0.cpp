class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int prev = -1;

        for (const int& num : nums)
        {
            int curr = num % 2;
            if (curr == prev) return false;
            else prev = curr;
        }
        return true;
    }
};