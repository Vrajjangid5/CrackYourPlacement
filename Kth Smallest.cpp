class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &nums, int k) {
        // code here
        
     
    
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            int element=nums[i];
            if(element<pq.top()){
                pq.pop();
                pq.push(element);
            }
        }
        return pq.top();
    
    }
};
