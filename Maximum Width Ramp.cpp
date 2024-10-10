class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> mini(n);
        vector<int> maxi(n);
        mini[0]=nums[0];
        maxi[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            mini[i]=min(mini[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            maxi[i]=max(maxi[i+1],nums[i]);
        }
        int ans=0;
        int i=0;
        int j=0;
       while(j<n){
        if(mini[i]<=maxi[j]){
            ans=max(ans,j-i);
            j++;
        }else{
            i++;
        }
       }
       return ans;

    }
};
