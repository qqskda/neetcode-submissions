class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0, count = 0;

        for (const int num : nums)
        {
            if (count == 0) maj = num;
            (maj == num) ? count++ : count--;
        }
        return maj;
    }
};