
class Solution {
   public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        int n = val.size();
        vector<pair<double, pair<int, int>>> items;
        
        for (int i = 0; i < n; ++i) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, {val[i], wt[i]}});
        }
        
        sort(items.rbegin(), items.rend());
        
        double maxValue = 0.0;
        for (int i = 0; i < n; ++i) {
            if (capacity == 0) break;
            double ratio = items[i].first;
            int weight = items[i].second.second;
            int value = items[i].second.first;
            
            if (capacity >= weight) {
                maxValue += value;
                capacity -= weight;
            } else {
                maxValue += value * ((double)capacity / weight);
                capacity = 0;
            }
        }
        
        return round(maxValue * 1000000) / 1000000;
    }
};
