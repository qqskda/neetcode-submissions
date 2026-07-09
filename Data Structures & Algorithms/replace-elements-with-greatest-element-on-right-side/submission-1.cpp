class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int currmax = -1;

        for (int i = arr.size()-1; i >= 0; --i)
        {
          int current = arr[i];
          arr[i] = currmax;
          currmax = max(currmax, current);
        }
        return arr;
    }
};