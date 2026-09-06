class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    // permutation: freq of the strings are equal.

    // 1. Get freq of S1
    // 2. Go over S2 with the size of S1 as a window size, form freq, and compare

    if (s1.length() > s2.length()) return false;

    array<int, 26> s1_freq = {0};
    array<int, 26> s2_freq = {0};

    for (const char ch : s1) {
      int chi = ch - 'a';
      s1_freq[chi]++;
    }
    for (int i = 0; i < s1.length(); ++i) {
      int chi = s2[i] - 'a';
      s2_freq[chi]++;
    }
    if (s1_freq == s2_freq) return true;

    int left = 0;
    // sliding window
    for (int right = s1.length(); right < s2.length(); ++right) {
      // not equal, lets slide
      int li = s2[left] - 'a';
      --s2_freq[li];
      ++left;
      // we still include the old right so skip
      int ri = s2[right] - 'a';
      ++s2_freq[ri];
      if (s1_freq == s2_freq) return true;
    }
    return false;
  }
};
