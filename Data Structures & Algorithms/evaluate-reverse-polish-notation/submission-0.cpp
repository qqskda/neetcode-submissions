class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    // 1 2 +
    // (1+2) 3 *
    // 9 4 -
    // 5

    stack<int> stk;
    for (int i = 0; i < tokens.size(); ++i) {
      if (tokens[i] != "+" && tokens[i] != "*" && tokens[i] != "-" && tokens[i] != "/")
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

        if (tokens[i] == "+")
          stk.push(a + b);
        else if (tokens[i] == "*")
          stk.push(a * b);
        else if (tokens[i] == "-")
          stk.push(a - b);
        else  // /
          stk.push(a / b);
      }
    }
    return stk.top();
  }
};
