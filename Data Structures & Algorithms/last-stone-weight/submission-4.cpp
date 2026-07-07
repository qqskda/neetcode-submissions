class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      std::priority_queue<int> pq(stones.begin(), stones.end());

      while (!pq.empty())
      {
        int x = pq.top();
        pq.pop();

        if (pq.empty()) return x;
        int y = pq.top();
        pq.pop();

        pq.push(x-y);
      }
      return 0;
    }
};
