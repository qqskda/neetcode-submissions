class Solution {
   public:
    vector<vector<int>> ret;

    void bt(const vector<int>& candidates, vector<int>& curr, int index, int target,
            bool skippedLast) {
        if (target == 0) {
            // no furhter check needed this path
            ret.push_back(curr);
            return;
        }

        if (index >= candidates.size() || target - candidates[index] < 0) {
            // no further check needed this path since candidates are already ordered
            return;
        }
        int num = candidates[index];

        // target - num >= 0
        if (!(skippedLast && index > 0 && candidates[index - 1] == num)) {
            curr.push_back(num);
            bt(candidates, curr, index + 1, target - num, false);
            curr.pop_back();
        }

        bt(candidates, curr, index + 1, target, true);
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Combinations: usually DFS style decision tree question that requires to visit
        //               each element in the given candidates.

        // Since the output should be unique, we can either use set, or skip
        // if the previous element matches to the current one when skip the previous one

        sort(candidates.begin(), candidates.end());
        vector<int> curr = {};
        bt(candidates, curr, 0, target, false);
        return ret;
    }
};
