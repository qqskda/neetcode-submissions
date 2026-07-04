class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        string num = to_string(x);

        // typical palindrome checker

        // index
        int left = 0, right = num.length() - 1;
        while (left <= right)
        {
            if (num[left++] != num[right--]) return false;
        }

        return true;

    }
};