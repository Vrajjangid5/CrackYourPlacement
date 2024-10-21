class Solution {
  public:
    int extractMax() {
        // your code here
         int maxi = H[0];
        
        swap(H[0], H[s]);
        
        s--;
        
        shiftDown(0);
        
        return maxi;
        
    }
};
