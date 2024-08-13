class Solution {
public:


   void findCombinations(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: if the target is met
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Base case: if the index goes out of bounds
        if (index >= candidates.size()) {
            return;
        }

        // Include the current candidate if it does not exceed the target
        if (candidates[index] <= target) {
            ds.push_back(candidates[index]);
            findCombinations(index + 1, target - candidates[index], candidates, ans, ds);
            ds.pop_back();
        }

        // Skip duplicates and move to the next candidate
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }

        // Exclude the current candidate and move to the next one
        findCombinations(index + 1, target, candidates, ans, ds);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates to handle duplicates
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        // Start the recursion
        findCombinations(0, target, candidates, ans, ds);

        return ans;
    }
};
