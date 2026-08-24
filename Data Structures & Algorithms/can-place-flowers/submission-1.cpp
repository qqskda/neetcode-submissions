class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // canPlant[i] = empty[i-1] && empty[i+1];

        int count = 0;

        int sz = flowerbed.size();
        bool left = false, right = false;
        for (int i = 0; i < sz; ++i)
        {
            // This spot is already taken, skip
            if (flowerbed[i] == 1) continue;

            // Setup for the boundaries
            if (i == 0) left = true;
            else left = flowerbed[i-1] == 0;
            if (i == sz-1) right = true;
            else right = flowerbed[i+1] == 0;

            if (left && right) // neighbours are empty
            {
                flowerbed[i] = 1;
                ++count;
            }
        }
        return count >= n;
    }
};