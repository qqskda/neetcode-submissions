class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // easy intuition: create hash map to store frequency, and then insert to priority_queue <frequency, num>
        // so that it is order by frequency, and then return as a vector (pop)

        unordered_map<int,int> umap;

        for (const int& num : nums) umap[num]++;

        priority_queue<pair<int,int>> pq;

        for (const auto& [num, freq] : umap)
        {
            pq.push((pair<int,int>){freq,num});
        }

        vector<int> ret;
        for (int i = 0; i < k; ++i)
        {
            ret.emplace_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
