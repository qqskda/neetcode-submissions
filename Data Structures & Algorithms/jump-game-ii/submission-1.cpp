class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();

        if (sz <= 1) return 0;

        int jump = 1;
        int index = 0;
        while (index < sz)
        {
            // 1. Among the ones I can jump, find the highest one
            int num = nums[index];
            int ceiling = min(num + index+1, sz);
            // ceiling is not index.
            if (ceiling >= sz) return jump;

            int candidate = 0;
            int next_index = index+1;
            for (int i = index+1; i < ceiling; ++i)
            {
                int new_num = nums[i] + i;
                if (new_num >= candidate)
                {
                    candidate = new_num;
                    next_index = i;
                }
                //early exit
                if (candidate >= sz-1) return jump+1;
            }
            // Jump to the best one we have
            index = next_index;
            jump += 1;
        }
        return jump;
    }
};
