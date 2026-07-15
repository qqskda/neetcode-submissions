class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Non adjacent planting
        // plant at i = check if there is a plant at i-1 and i+1
        
        int prev = 0, next = 0;
        int count = 0;
        for (int i = 0; i < flowerbed.size(); ++i)
        {
          if (i == 0) prev = 0;
          else prev = flowerbed[i-1];

          if (i == flowerbed.size()-1) next = 0;
          else next = flowerbed[i+1];

          if (!prev && !next && flowerbed[i] != 1)
          {
            count++;
            flowerbed[i] = 1;
          }
        }
        return n <= count;
    }
};