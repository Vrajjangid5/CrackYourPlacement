int missingNumber(vector<int>&a, int n) {
    // Write your code here.
    int sum=n*(n+1)/2;
    int sum2=0;
    for(int i=0;i<a.size();i++){
        sum2+=a[i];
    }
    return sum-sum2;
}
