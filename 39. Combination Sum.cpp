class Solution {
public:
    void solve(int i, int curr, int sum, vector<int>& ds, vector<int>& nums, int n, vector<vector<int>>& ans) {
        // Base case: if current sum equals target sum
        if (curr == sum) {
            ans.push_back(ds);
            return;
        }

        // Base case: if index goes out of bounds or current sum exceeds the target
        if (i >= n || curr > sum) {
            return;
        }

        // Include the current element and stay on the same index (i) (for multiple uses)
        ds.push_back(nums[i]);
        solve(i, curr + nums[i], sum, ds, nums, n, ans);

        // Backtrack: remove the last added element and move to the next index
        ds.pop_back();
        solve(i + 1, curr, sum, ds, nums, n, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, 0, target, ds, candidates, candidates.size(), ans);
        return ans;
    }
};
