class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> umap;

        for (const int num : nums)
        {
          umap[num]++;
        }

        sort(nums.begin(), nums.end(), [&](const int a, const int b){
          // should a comes before b?
          if (umap[a] != umap[b]) return umap[a] < umap[b]; // if a has smaller freq

          // if a is bigger
          return a > b;
        });
        return nums;
    }
};