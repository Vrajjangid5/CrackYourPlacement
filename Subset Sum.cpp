bool solve(int i, int n, int sum, vector<int>& a, vector<vector<int>>& dp) {
    if (sum == 0) {
        return true; // Found a valid subset
    }
    if (i >= n || sum < 0) {
        return false; // No valid subset possible
    }
    if (dp[i][sum] != -1) {
        return dp[i][sum]; // Return previously computed result
    }

    // Try to pick the current element
    if (a[i] <= sum) {
        if (solve(i + 1, n, sum - a[i], a, dp)) {
            return dp[i][sum] = true;
        }
    }

    // Try not to pick the current element
    if (solve(i + 1, n, sum, a, dp)) {
        return dp[i][sum] = true;
    }

    // If no valid subset is found
    return dp[i][sum] = false;
}



bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return solve(0,n,k,a,dp);
}
