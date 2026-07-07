class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    if (stones.size() == 1) return stones[0];
    for (int i = 0; i < stones.size(); ++i) {
      sort(stones.begin(), stones.end(), greater<int>());
      if (stones[0] < stones[1])
        stones[0] = stones[1] - stones[0];
      else
        stones[0] = stones[0] - stones[1];

      stones[1] = 0;
    }
    return stones[0];
  }
};
