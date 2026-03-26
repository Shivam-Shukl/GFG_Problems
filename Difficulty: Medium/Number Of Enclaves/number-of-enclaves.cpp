
class Solution {
  public:
    void dfs(vector<vector<int>> &grid,int i,int j,vector<vector<bool>> &vis){
        
        int n = grid.size();
        int m = grid[0].size();
        
        vis[i][j] = true;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        for(int k = 0;k<4;k++){
            int row = i + dx[k];
            int col = j + dy[k];
            if(row>= 0 && row<n && col >= 0 && col <m && vis[row][col] == false && grid[row][col] == 1){
                dfs(grid,row,col,vis);
            }
        }
    }
   
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        // what is the plan 
        // insert all the boundry 1 and follow flood fill algo to mar as 1 as visited.
        // in the last count where it is 0 and grid[i][j] == 1;
        // u can follow either dfs or bfs but here i will use dfs for flood fill.
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i =0;i<n;i++){
            if(grid[i][0] == 1 && vis[i][0] == false){
                dfs(grid,i,0,vis);
            }
            if(grid[i][m-1] == 1 && vis[i][m-1] == false){
                dfs(grid,i,m-1,vis);
            }
        }
        for(int j = 0;j<m;j++){
            if(grid[0][j] == 1 && vis[0][j] == false){
                dfs(grid,0,j,vis);
            }
            if(grid[n-1][j] == 1 && vis[n-1][j] == false){
                dfs(grid,n-1,j,vis);
            }
        }
        
        int cnt = 0;
        
        for(int i =0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
