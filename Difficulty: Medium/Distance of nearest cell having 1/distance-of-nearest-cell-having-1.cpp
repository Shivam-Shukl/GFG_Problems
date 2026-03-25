class Solution {
  public:
    void bfs(vector<vector<int>>& grid,vector<vector<bool>> &vis,vector<vector<int>> &dis){
        // put all the one at once in the queue
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>, int>> q;
        for(int i =0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    dis[i][j] = 0;
                    vis[i][j] = true;
                    q.push({{i,j},0});
                }
            }
        }
        
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();
            int dx[4] = {0,0,-1,1};
            int dy[4] = {-1,1,0,0};
            
            for(int k =0;k<4;k++){
                int row = i + dx[k];
                int col = j + dy[k];
                if(row >= 0 && row <n && col>= 0 && col < m && vis[row][col] == false){
                    vis[row][col] = true;
                    if(dis[row][col] == -1){
                        dis[row][col] = d+1;
                    }else{
                        dis[row][col] = min(d+1,dis[row][col]);
                    }
                    q.push({{row,col},d+1});
                }
            }
            
        }
    }
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dis(n,vector<int>(m,-1));
        
        bfs(grid,vis,dis);
        return dis;
        
    }
};  