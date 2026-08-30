class Solution {
public:
    bool canJump(vector<int>& nums) {
        // nums[i] = n
        // n means can jump [1,n]

        // Q: Can we reach the last index?
        // A: From the backside, keep repeating to find the least index that is available to hit the current destination since it can jump [1,n].
        int sz = nums.size();

        if (sz <= 1) return true;

        // sz is at least 2
        int index = sz-1;
        bool ret = false;
        for (int i = sz-2; i >= 0; --i)
        {
            int num = nums[i];
            int distance = index - i;
            if (num >= distance)
            {
                index = i;
                ret = true;
            }
            else
                ret = false;
        }
        return ret;
    }
};
