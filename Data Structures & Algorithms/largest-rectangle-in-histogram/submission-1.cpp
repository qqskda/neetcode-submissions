class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;
        int maxArea = INT_MIN;
        for (int i = 0; i < heights.size(); ++i)
        {
            int height = heights[i];
            int start = i;
            while (!stk.empty() && stk.top().second > height)
            {
                // if there is ones that are higher than me, those are no longer available
                // to the right side.
                auto [prevStart, prevHeight] = stk.top();
                stk.pop();
                // i - prevStart => width
                // lets say i is 2, prevStart is 0
                // 0-1 1-2 so i-prevStart is width
                maxArea = max(maxArea, prevHeight * (i - prevStart));
                start = prevStart;
            }

            stk.push({start, height}); 
        }
        // now stack has leftovers that requires calculation
        while (!stk.empty())
        {
            int width = heights.size() - stk.top().first;
            maxArea = max(maxArea, stk.top().second * width);
            stk.pop();
        }
        return maxArea;
    }
};
