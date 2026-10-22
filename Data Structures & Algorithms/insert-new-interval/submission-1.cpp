class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Loop through intervals has three cases

        // 1. newInterval is completely before the interval
        // 2. newInterval is completely after the interval
        // 3. newInterval is overlapping

        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); ++i)
        {
            vector<int> interval = intervals[i];

            if (newInterval[1] < interval[0]) // case 1
            {
                ret.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(ret));
                return ret;
            }
            else if (newInterval[0] > interval[1]) // case 2 - append and move on
            {
                ret.push_back(interval);
            }
            else // case 3
            {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        ret.push_back(newInterval);

        return ret;
    }
};
