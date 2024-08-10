class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxProduct = nums[0];
        int curMin = nums[0];
        int curMax = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            // When num is negative, swapping curMin and curMax is needed
            if (num < 0) {
                swap(curMin, curMax);
            }

            // Update curMax and curMin
            curMax = max(num, curMax * num);
            curMin = min(num, curMin * num);

            // Update the global maximum product
            maxProduct = max(maxProduct, curMax);
        }

        return maxProduct;
    }
};
