class Solution {
public:

    int MOD=1000000007;
    long Pow(long x,long n){
        if(n==0) return 1;
        long temp=Pow(x,n/2);
        if(n%2==0){
            return (temp*temp)%MOD;
        }else{
            return (x*temp*temp)%MOD;
        }
    }


    int countGoodNumbers(long long n) {
        long even=(n+1)/2;
        long odd=n/2;
        long evenA=Pow(5,even);
        long oddA=Pow(4,odd);
        return (evenA*oddA)%MOD;
      }
};
