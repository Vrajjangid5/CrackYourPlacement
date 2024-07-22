class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n=nums.size()-1;
        int reac=0;
        for(int i=0;i<=n;i++){
            if(reac<i) return false;
            reac=max(reac,i+nums[i]);

        }
        return true;
    }
};
