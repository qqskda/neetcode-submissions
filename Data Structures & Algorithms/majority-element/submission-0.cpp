class Solution {
public:
    int majorityElement(vector<int>& nums) {

        pair<int, int> track{nums.front(),1};

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == track.first || track.second == 0)
            {
                track.first = nums[i];
                track.second++;
            }
            else
            {
                // not same
                track.second--;
            }
        }

        return track.first;
    }
};