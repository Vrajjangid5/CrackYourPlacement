class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int ans=INT_MIN;
        int j=height.size()-1;
        while(i<j){
            int left=height[i];
            int right=height[j];
            int m=min(left,right);
            ans=max(ans,m*(j-i));
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};
