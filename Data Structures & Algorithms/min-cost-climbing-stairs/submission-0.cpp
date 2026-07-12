class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Start either 0 or 1
        // Pay
        // cost[i] = min cost to be at i + price to get out
        // we want min(cost[n-2], cost[n-1]);

        // 1 2 1 2 1 1 1
        // 1 2 2 4 3 4 4

        int sz = cost.size();
        if (sz == 2) return min(cost[0], cost[1]);
        for (int i = 2; i < sz; ++i)
        {
            cost[i] = min(cost[i-1], cost[i-2]) + cost[i];
        }
        return min(cost[sz-1], cost[sz-2]);

    }
};
