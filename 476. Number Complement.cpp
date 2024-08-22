class Solution {
public:
    int findComplement(int num) {
        int ans = 0, i = 0;
        while(num > 0) ans = ans + !(num%2) * pow(2,i++) , num/=2;
        return ans;
    }
};
