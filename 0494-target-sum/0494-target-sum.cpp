class Solution {
public:
    int countSubsetsWithSum(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[n + 1][target + 1];

        // initialize
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (j == 0) dp[i][j] = 1;   // one way: empty subset
                else if (i == 0) dp[i][j] = 0; // no elements, non-zero sum
                else dp[i][j] = 0;
            }
        }

        // fill DP
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        // feasibility check
        if ((S + total) % 2 != 0 || S > total || S < -total) return 0;
        int target = (S + total) / 2;
        return countSubsetsWithSum(nums, target);
    }
};
