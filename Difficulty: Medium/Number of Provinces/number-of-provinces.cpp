// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node) {
      
        for (int neigh : adj[node]) {
            if (vis[neigh] == false) {
                vis[neigh] = true;
                dfs(adj, vis, neigh);
            }
        }
    }
    int numProvinces(vector<vector<int>> V, int n) {
        // code here
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                } else {
                    if (V[i][j] == 1) {
                        adj[i].push_back(j);
                    }
                }
            }
        }

        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                vis[i] = true;
                dfs(adj, vis, i);
                cnt++;
            }
        }
        return cnt;
    }
};