class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);  // Create a prefix sum array
        
        // Fill the prefix sum array
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        
        int ans = 0;
        
        // Calculate the maximum score
        for (int i = 0; i <= k; ++i) {
            int currentSum = sum[i] + (sum[n] - sum[n - (k - i)]);
            ans = max(ans, currentSum);
        }
        
        return ans;
    }
};
