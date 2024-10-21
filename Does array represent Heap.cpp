class Solution{
    public:
    
    
    
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
         if(n==1) return true;
        for(int i =0;i<=n/2-1;i++){
            int l = 2*i+1;
            int r = 2*i+2;
            if(arr[i]<arr[l] || arr[i]<arr[r]){
                return false;
            }
        }
        return true;
    }
};
