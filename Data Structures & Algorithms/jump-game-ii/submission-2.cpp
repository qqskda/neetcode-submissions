class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int left = 0;
        int right = 0;

        int sz = nums.size();
        while (right < sz-1)
        {
            int furthest = 0;
            for (int i = left; i <= right; ++i)
            {
                furthest = max(furthest, i + nums[i]);
            }
            // we checked between [left, right]
            left = right+1;
            right = furthest;

            // between [left, right], we have to jump once
            // furthest is where we can go if we jump once among the candidates
            ret++;
        }
        return ret;
    }
};
