class Solution {
  public:

    void bfs(vector<vector<int>>& grid,
             vector<vector<bool>>& vis,
             set<vector<pair<int,int>>>& st,   
             int i, int j) {

        vector<pair<int,int>> v;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i, j});

        v.push_back({0, 0});
        vis[i][j] = true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int r = row + dx[k];
                int c = col + dy[k];

                if (r >= 0 && r < n && c >= 0 && c < m &&
                    vis[r][c] == false && grid[r][c] == 1) {

                    vis[r][c] = true;
                    q.push({r, c});
                    v.push_back({r - i, c - j});
                }
            }
        }

        st.insert(v);
    }

    int countDistinctIslands(vector<vector<int>>& grid) {

        set<vector<pair<int,int>>> st;   

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    bfs(grid, vis, st, i, j);
                }
            }
        }

        return st.size();
    }
};