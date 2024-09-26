class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (isDivisible(i)) ans.push_back(i);
        }
        return ans;
    }

    bool isDivisible(int x) {
        int num = x;
        while (num) {
            int digit = num % 10;
            if (digit == 0 || x % digit != 0) return false;  // Check for zero or non-dividing digit
            num /= 10;
        }
        return true;
    }
};
