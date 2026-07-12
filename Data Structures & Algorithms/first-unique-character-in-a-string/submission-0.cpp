class Solution {
public:
    int firstUniqChar(string s) {

        // -1 : not seen
        // -2, -3... : has seen before
        // positive: index
        // If found positive, then set to -2
        array<int,26> arr; arr.fill(-1);
        for (int i = 0; i < s.length(); ++i)
        {
          char ch = s[i];
          int val = arr[ch-'a'];
          if (val >= 0)
          {
            // not unique anymore
            arr[ch-'a'] = -2;
          }
          else if (val == -1)
          {
            // first time seeing
            arr[ch-'a'] = i;
          }
          else arr[ch-'a']--;

          cout << ch << " " << arr[ch-'a'] << endl;
        }

        // now find the lowest index that is >= 0
        int ret = INT_MAX;
        for (const int num : arr)
        {
          if (num >= 0) ret = min(num, ret);
        }
        return (ret >= 0 && ret != INT_MAX) ? ret : -1;

    }
};