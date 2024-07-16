class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int k =i;
            if(nums[i]==0){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==0){
                    continue;
                }
                swap(nums[k],nums[j]);
                k++;
            }
            }
        }
    }
};
