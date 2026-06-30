class Solution {
 public:
  int evalRPN(vector<string>& tokens) {

    static const unordered_map<string, std::function<int(int,int)>> ops =  {
        {"+", [](int a, int b){ return a+b; }},
        {"*", [](int a, int b){ return a*b; }},
        {"/", [](int a, int b){ return a/b; }},
        {"-", [](int a, int b){ return a-b; }},
    };
    // 1 2 +
    // (1+2) 3 *
    // 9 4 -
    // 5

    stack<int> stk;
    for (int i = 0; i < tokens.size(); ++i) {
        auto itr = ops.find(tokens[i]);
      if (itr == ops.end())
      {
        int num = stoi(tokens[i]);
        stk.push(num);
      }
      else {
        // operands
        int b = stk.top();
        stk.pop();
        int a = stk.top();
        stk.pop();

        stk.push(itr->second(a,b));
      }
    }
    return stk.top();
  }
};
