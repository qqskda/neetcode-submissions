class Solution {
   public:
    vector<vector<int>> ret;
    void bt(const vector<int>& candidates, vector<int>& curr, int index, int target) {
        if (target == 0) {
            ret.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // i.e., 1 2 2 5
            // First 2 is picked up previously
            // Second 2 is picked up previously at the below bt calls.
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // No need to check further since candidates are sorted
            if (candidates[i] > target) break;

            // Take the curr number
            curr.push_back(candidates[i]);

            bt(candidates, curr, i + 1, target - candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        bt(candidates, curr, 0, target);

        return ret;
    }
};
