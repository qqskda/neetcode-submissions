class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // 1 -> 3
        // 4 -> 3
        // 2 -> 3

        // Judge should know that if everyone trusts it.
        // Just should not point anyone.
        // Two separate maps for trusts, trusted.

        // We just need to know the list of people who do not trust anyone
        // We just need to know the list of people who are trusted by all.
        // map<bool, int> bool: does it trust anyone. Int: number of people trsuts.

        unordered_map<int, pair<bool, int>> umap;
        for (int i = 0; i < trust.size(); ++i)
        {
          int x = trust[i][0];
          int y = trust[i][1];
          umap[x].first = true;
          umap[y].second++;
        }

        for (auto pa : umap)
        {
          if (!pa.second.first && pa.second.second == n-1) return pa.first;
        }
        return -1;
    }
};