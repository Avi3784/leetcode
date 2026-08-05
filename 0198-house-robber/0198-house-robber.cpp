class Solution {
public:
    unordered_map<int ,int >dp;

    int solve(vector<int>& nums,int i,int n){
        if(i>=n){return 0;}
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        int steal=nums[i]+solve(nums,i+2,n);
        int skip=solve(nums,i+1,n);

        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int i;
        int n=nums.size();
        

        int ans=solve(nums,0,n);
        return ans ;

     }
};