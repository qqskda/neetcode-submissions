class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> a(n, false);
        vector<int> b(n, 0);

        for (int i = 0; i < trust.size(); ++i)
        {
          int x = trust[i][0];
          int y = trust[i][1];

          a[x-1] = true;
          b[y-1]++;
        }

        for (int i = 0; i < n; ++i)
        {
          if (a[i] == false && b[i] == n-1) return i+1;
        }
        return -1;
    }
};