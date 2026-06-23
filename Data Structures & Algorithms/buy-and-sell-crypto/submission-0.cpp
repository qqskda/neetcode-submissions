class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            int sell_price = prices[i];
            int profit = sell_price - minBuy;
            maxProfit = max(profit, maxProfit);
            minBuy = min(minBuy, sell_price);
        }
        return maxProfit;
    }
};
