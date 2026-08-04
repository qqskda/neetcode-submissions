class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Priority queue (min-heap) could be a way to go,
        // But we can approach like two pointers window.

        int sz = intervals.size();
        if (sz <= 1) return intervals;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ret;
        int left = intervals[0][0], right = intervals[0][1];
        bool pushed = false;
        for (int i = 0; i < sz; ++i)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];

            if (left <= l && l <= right)
            {
                // overlapping -> expand
                right = max(right, r);
                pushed = false;
            }
            else
            {
                // not overlapping
                ret.push_back({left, right});
                left = l;
                right = r;
                pushed = true;
            }
        }
        // Don't forget the uncomitted overlapping
        ret.push_back({left, right});

        return ret;
    }
};
