class Solution{
      int mod = 1000000007;
    int f(int idx,int arr[],int n,int sum,vector<vector<int>> &dp){
        if(idx>=n){
            if(sum == 0)return 1;
            return 0;
        }
        
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        

        int pick = 0;
        if(idx<n && arr[idx]<=sum)pick = f(idx+1,arr,n,sum - arr[idx],dp) % mod;
        
        int notpick = f(idx+1,arr,n,sum,dp)%mod;
        
        return dp[idx][sum] = ((pick%mod) + (notpick%mod))%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    
	    vector<vector<int>> dp(n,vector<int> (sum + 1,-1));
	    
        return f(0,arr,n,sum,dp)%mod;
	}
	  
};
