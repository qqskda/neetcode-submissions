class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1) return sz;

        unordered_set<int> hash(nums.begin(), nums.end());

        int max_con = 0;
        int cur_con = 0;
        int curr_num = 0;
        for (const int& num : hash)
        {
            if (!hash.contains(num-1))
            {
                curr_num = num;
                while(hash.contains(curr_num))
                {
                    curr_num++;
                    cur_con++;
                }
                max_con = max(max_con, cur_con);
            }
            cur_con = 0;
        }
        return max_con;
    }
};
