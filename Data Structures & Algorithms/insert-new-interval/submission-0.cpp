class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 1. if intervals empty => return newInterval.
        if (intervals.empty()) return {newInterval};

        // 2.1 Append the ones that we surely know that we will not overlap
        vector<vector<int>> res = {};
        int i = 0;
        for (i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][1] < newInterval[0]) res.push_back(intervals[i]);
            else break;
        }

        // 2.2 lets deal with overlapping
        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }

        res.push_back(newInterval);

        // 2.3 clean up
        for (; i < intervals.size(); ++i)
        {
            res.push_back(intervals[i]);
        }

        return res;
    }
};
