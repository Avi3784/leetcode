class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp[i][j] = minimum coins needed using first i coins to make amount j
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // Step 1: Initialize
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j == 0) {
                    dp[i][j] = 0; // 0 coins needed to make amount 0
                } else if (i == 0) {
                    dp[i][j] = INT_MAX - 1; // impossible if no coins
                }
            }
        }

        // Step 2: Fill the table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] > j) {
                    // coin too large, skip it
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // either skip the coin or use it
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }

        // Step 3: Answer
        return (dp[n][amount] == INT_MAX - 1) ? -1 : dp[n][amount];
    }
};
