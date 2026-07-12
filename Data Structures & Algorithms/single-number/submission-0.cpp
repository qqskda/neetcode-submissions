class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // binary bitwise xor
        // 0 xor 0 = 0
        // 1 xor 0 = 1
        // 0 xor 1 = 1
        // 1 xor 1 = 0

        int i = 0;

        for (const int num : nums)
        {
          i ^= num;
        }
        return i;
    }
};
