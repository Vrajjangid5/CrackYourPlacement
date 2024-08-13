class Solution {
public:

    int solve(int sum,vector<int>&nums,vector<int>&dp){
        if(sum<0) return 0;
        if(sum==0) return 1;
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=solve(sum-nums[i],nums,dp);
        }
        dp[sum]=ans;
        return dp[sum];
    }



    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return solve(target,nums,dp);
    }
};
