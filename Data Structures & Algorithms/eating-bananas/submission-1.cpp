class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // l is min r is max k value 
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r)
        {
            // mid value 
            int k = (l+r)/2;

            long long totalTime = 0;
            for (int p : piles) totalTime += ceil(static_cast<double>(p) / k);

            // sum of hours it takes with value k <= h
            // meaning we can lower the k.
            if (totalTime <= h)
            {
                res = k;
                r = k-1;
            }
            else // k is too low.
            {
                l = k+1;
            }
        }
        return res;
    }
};
