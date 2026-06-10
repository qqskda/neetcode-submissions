class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 1. array is sorted.
        // 2. First index
        // 3. ofc, cannot use the same element.
        // O(1) space.

        // You can use two pointers starting from start and end.
        // if A+D < target, shift left and check B+D
        // if A+D > target, shift right and check A+C

        int left = 0;
        int right = numbers.size()-1;

        while (left < right)
        {
            if (numbers[left] + numbers[right] < target)
            {
                // we need bigger number
                left++;
            }
            else if (numbers[left] + numbers[right] == target)
            {
                // jackpot return index
                return {left+1, right+1};
            }
            else
            {
                // need smaller number
                right--;
            }
        }
        return {};
    }
};
