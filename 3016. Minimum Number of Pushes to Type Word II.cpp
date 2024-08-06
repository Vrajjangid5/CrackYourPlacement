class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        // map<char,int>mp;
         unordered_map<char, int> freq;
        multimap<int, char, greater<int>> freqMap; 
        for(auto &ch:word){
            freq[ch]++;
        }
         vector<int> frequencies;
        for (auto &entry : freq) {
            frequencies.push_back(entry.second);
        }
        sort(frequencies.rbegin(), frequencies.rend()); // Sort in descending order
        
        // Now map these frequencies to key presses
    //    int ans = 0;
        int count = 0;
        for (int i = 0; i < frequencies.size(); i++) {
            if (count < 8) {
                ans += frequencies[i] * 1; // First 8 characters get 1 press each
            } else if (count < 16) {
                ans += frequencies[i] * 2; // Next 8 characters get 2 presses each
            } else if (count < 24) {
                ans += frequencies[i] * 3; // Next 8 characters get 3 presses each
            } else {
                ans += frequencies[i] * 4; // Remaining characters get 4 presses each
            }
            count++;
        }

        return ans;

    }
};
