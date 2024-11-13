class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> graph(n + 1);
        vector<int> vis(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a[0].size(); j++) {
                if (a[i][j]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (vis[i])continue;
            ans++;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                if (vis[node])continue;
                vis[node] = 1;

                for (auto& i : graph[node]) {
                    if (!vis[i])q.push(i);
                }
            }
        }

        return ans;
    }
};
