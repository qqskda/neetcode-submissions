class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 1. if the sum of cost is higher than gas, it is impossible.
        int total_gas = accumulate(gas.begin(), gas.end(), 0);
        int total_cost = accumulate(cost.begin(), cost.end(), 0);
        if (total_gas < total_cost) return -1;

        int start = 0;
        int curr_gas = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            if (start == -1)
            {
                // This is new starting point
                start = i;
            }
            curr_gas += gas[i];

            if (cost[i] > curr_gas)
            {
                // dont have enough gas. Reset starting point
                start = -1;
                curr_gas = 0;
                continue;
            }
            else
            {
                // we do have enough gas
                curr_gas -= cost[i];
            }
        }

        return start;
    }
};
