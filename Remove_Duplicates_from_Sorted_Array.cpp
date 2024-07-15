class Solution {
public:

    // Brute Force Solution - Using a set to find unique elements
    int solution1(vector<int>& nums) {
        set<int> s;

        // Insert the elements into the set
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        // Now insert the unique elements back to the array
        int index = 0;
        for (auto it : s) {
            nums[index] = it;
            index++;
        }

        return index;
    }

    /*
        Analysis:
        Time Complexity: O(N log N) + O(N) ==> O(N log N)
        Space Complexity: O(N) --> Because we have used the set
    */

    // Optimal Solution - Using the two-pointer approach
    int solution2(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[i] != nums[j]) {
                nums[i + 1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }

    /*
        Analysis:
        Time Complexity: O(N)
        Space Complexity: O(1)
    */

    int removeDuplicates(vector<int>& nums) {
        return solution2(nums);
    }
};
