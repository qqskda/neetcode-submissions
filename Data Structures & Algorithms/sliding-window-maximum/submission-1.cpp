class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        priority_queue<pair<int,int>> max_pq;

        for (int i = 0; i < k; ++i)
        {
            max_pq.push({nums[i], i});
        }

        vector<int> maxs = {};
        maxs.reserve(nums.size() - k + 1);
        maxs.push_back(max_pq.top().first);
        for (int i = k; i < nums.size(); ++i)
        {
            int num = nums[i];
            max_pq.push({num, i});
            while (!max_pq.empty() && max_pq.top().second <= i-k)
                max_pq.pop(); // drain out of bound
            
            maxs.push_back(max_pq.top().first);
        }
        return maxs;
    }
};
