class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // Each index = max to my right.
        // Starting from the right side makes sense to me
        // base case: size should be 1
        int arrsz = arr.size();
        if (arrsz == 1) return {-1};

        int farmax = arr.back();
        vector<int> ret(arrsz, -1);
        for (int i = arrsz-2; i >= 0; --i)
        {
          ret[i] = farmax;
          farmax = max(farmax, arr[i]);
        }
        return ret;
    }
};