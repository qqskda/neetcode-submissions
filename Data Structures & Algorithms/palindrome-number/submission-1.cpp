class Solution {
public:
    bool isPalindrome(int x) {
        // Approach using mod
        if (x < 0) return false;
        vector<int> vec;

        while (x > 0)
        {
            vec.emplace_back(x % 10);
            x /= 10;
        }

        for (int i = 0; i < vec.size()/2; ++i)
        {
            if (vec[i] != vec[vec.size()-1-i]) return false;
        }
        return true;
    }
};