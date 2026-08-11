class Solution {
public:
    void dfs(vector<string>& ret, string& curr, int opened, int closed, const int& n)
    {
        if (closed == n)
        {
            // we are done with the string
            ret.push_back(curr);
            return;
        }

        // we can open ; this allows us to always open first
        if (opened < n)
        {
            curr.push_back('(');
            dfs(ret, curr, opened+1, closed, n);
            curr.pop_back();
        }

        // we can close
        if (closed < opened)
        {
            curr.push_back(')');
            dfs(ret, curr, opened, closed+1, n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // n = 2
        // (()) ()()
        // open open close close
        // open close open close
        // Mindful that first we should open, and end with close

        vector<string> ret = {};
        string curr = "";
        int opened = 0, closed = 0;
        dfs(ret, curr, opened, closed, n);
        return ret;
    }
};
