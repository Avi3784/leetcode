class Solution {
public:
    unordered_map<int,int>dp;
    int climbStairs(int n,int i=0) {
        
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }

        if(dp.find(i)!=dp.end()){
            return dp[i];
        }

        int ans=climbStairs(n,i+1)+climbStairs(n,i+2);
        dp[i]=ans;
        return ans;

    }
};