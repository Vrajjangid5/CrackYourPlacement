  long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    std::sort(a.begin(), a.end());
    
    // Initialize the minimum difference to a large value
    long long mini = LLONG_MAX;
    
    // Traverse the array to find the minimum difference
    for (long long i = 0; i + m - 1 < n; i++) {
        long long sub = a[i + m - 1] - a[i];
        if (sub < mini) {
            mini = sub;
        }
    }
    
    return mini;}
