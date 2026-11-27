class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int>gain(n, 0);

        for (int i = 0;  i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (items[j][0] % items[i][0] == 0){
                    gain[i]++;
                }
            }
        }
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            for (int w = budget; w >= price; --w) {
                dp[w] = max(dp[w], dp[w - price] + gain[i]);           
            }
            for (int w = price; w <= budget; ++w) {
                dp[w] = max(dp[w], dp[w - price] + 1);
            
            }
        }
        return dp[budget];
    }
};