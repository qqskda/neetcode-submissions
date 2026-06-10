class Solution {
   public:
    bool isPalindrome(string s) {
        // 1단계: 필터링된 문자열 먼저 만들기
        string filtered;
        for (char c : s) {
            if (isalnum(c)) filtered += tolower(c);
        }

        // 2단계: stack으로 palindrome 체크
        int n = filtered.size();
        int mid = n / 2;
        stack<char> stk;

        for (int i = 0; i < n; i++) {
            if (i < mid) {
                stk.push(filtered[i]);
            } else if (i == mid && n % 2 == 1) {
                continue;
            } else {
                if (stk.top() != filtered[i]) return false;
                stk.pop();
            }
        }
        return true;
    }
};
