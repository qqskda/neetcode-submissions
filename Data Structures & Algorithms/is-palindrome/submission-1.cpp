class Solution {
public:
    bool isPalindrome(string s) {
        // Palindrome: order does matter
        // 1. Two pointers travelling from start and end.
        // 2. Stack -> careful when to start popping.

        // case insensitive. only alphanumeric.

        int sz = s.length();

        int left = 0;
        int right = sz-1;
        while (left < right)
        {
            // skip non alphanumeric
            while (left < right && !isalnum(s[left]) ) left++;
            while (left < right && !isalnum(s[right]) ) right--;

            if (tolower(s[left]) != tolower(s[right])) return false;
            else{
                left++;
                right--;
            }
        }

        return true;

    }
};
