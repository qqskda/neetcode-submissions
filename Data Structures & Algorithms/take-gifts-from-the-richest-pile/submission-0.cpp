class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // priority queue 

        priority_queue<int> pq(gifts.begin(), gifts.end());

        while (k)
        {
          int top = pq.top();
          pq.pop();

          pq.push(sqrt(top));
          k--;
        }

        int ret = 0;
        while(!pq.empty())
        {
          ret += pq.top();
          pq.pop();
        }
        return ret;
    }
};