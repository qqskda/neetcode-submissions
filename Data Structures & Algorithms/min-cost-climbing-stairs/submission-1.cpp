class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Start either 0 or 1
        // Pay
        // cost[i] = min cost to be at i + price to get out
        // we want min(cost[n-2], cost[n-1]);

        // 1 2 1 2 1 1 1
        // 1 2 2 4 3 4 4

        int prev1 = cost[1];
        int prev2 = cost[0];
        int sz = cost.size();
        for (int i = 2; i < sz; ++i)
        {
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);

    }
};
