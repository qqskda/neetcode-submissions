class Solution {
public:
    int findLucky(vector<int>& arr) {
        // lucky: number A == reps of A
        // umap => O(n)+O(n).

        unordered_map<int,int> umap;
        
        for (int i = 0; i < arr.size(); ++i)
        {
          umap[arr[i]]++;
        }

        int lucky = -1;
        for (const auto& [value, count] : umap)
        {
          if (value == count) lucky = max(lucky, value);
        }
        return lucky;
    }
};