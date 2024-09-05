#include <climits> // for INT_MIN
#include <vector>
int solver(vector<int> &houses, int n,int i,vector<int> &dp){
	
	if(i>=n){
		return 0;
	}
	if(dp[i]!=-1){
		return dp[i];
	}
	int include=INT_MIN;
	include=solver(houses, n, i+2,dp)+houses[i];
	int exclude=solver(houses, n,i+1,dp);
	return dp[i]=max(include,exclude);

}


int maxMoneyLooted(vector<int> &houses, int n)
{
	/*
		Write your code here.
		Don't write main().
	 	Don't take input, it is passed as function argument.
	 	Don't print output.
	 	Taking input and printing output is handled automatically.
	*/
	int i=0;
	vector<int>dp(n,-1);
	int ans=solver(houses,n, i,dp);
	// cout<<ans<<endl;
	return ans;

}
