class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fmap;
        
        for (int n : nums) {
            fmap[n]++;
        }
        

        //The priority queue (or max-heap) by default sorts 
        //based on the first element of the pair. Since we want
        //to extract the elements with the highest frequency,
        //we need to use frequency as the first element of the pair.
        //This ensures that elements with higher frequencies appear
        //at the top of the heap.

        priority_queue<pair<int, int>> priority_queue;
        for (const auto& i : fmap) {
            priority_queue.push({i.second, i.first});
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(priority_queue.top().second);
            priority_queue.pop();
        }
        return ans;
    }
};
