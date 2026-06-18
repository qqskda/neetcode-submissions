class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // It is basically asking the shortest distance from A to B
        // where A < B.

        // (30,0)
        // (38,0)
        // (38,0) (30,0)
        // (38,0) (36,0)
        // (38,0) (36,0) (35,0)
        // (40,0)
        // (40,0), (28,0)

        // {temp, index}
        stack<pair<int, int>> stk;
        vector<int> ret(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            int temp = temperatures[i];
            if (!stk.empty()) {
                while (!stk.empty()) {
                    if (temp > stk.top().first) {
                        // Found, update and pop
                        int top_index = stk.top().second;
                        ret[top_index] = i - top_index;
                        stk.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            // Append myself to stack
            stk.push({temp, i});
        }
        return ret;
    }
};
