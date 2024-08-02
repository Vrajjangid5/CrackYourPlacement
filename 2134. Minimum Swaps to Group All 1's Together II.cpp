class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int i=0;
        int j=0;
        int n=nums.size();
        int curr=0;
        int maxi=0;
        while(i<2*n){
            if(nums[i%n]==1){
                curr++;
            }
            if(i-j+1>sum){
                curr-=nums[j%n];
                j++;
            }
            maxi=max(curr,maxi);
            i++;
        }
        return sum-maxi;
    }
};
