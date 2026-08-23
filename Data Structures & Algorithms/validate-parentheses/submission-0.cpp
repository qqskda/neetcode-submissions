class Solution {
public:
    bool isValid(string s) {
        // To be valid: it is pair [open, close]

        stack<char> stk;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (const char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                stk.push(ch);
            else
            {
                if (!stk.empty() && stk.top() == closeToOpen[ch])
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};
