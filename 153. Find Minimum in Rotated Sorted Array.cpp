class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0;
        int e=arr.size()-1;
        int mid=l+(e-l)/2;
        int ans=INT_MAX;
        while(l<=e){
            if(arr[l]<=arr[mid]){
                ans=min(ans,arr[l]);
                l=mid+1;
            }else{
                 e=mid-1;
                ans=min(ans,arr[mid]);
               
            }
            mid=l+(e-l)/2;
        }
        return ans;
    }
};
