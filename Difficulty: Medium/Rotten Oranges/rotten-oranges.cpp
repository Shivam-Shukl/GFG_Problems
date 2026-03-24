class Solution {
  public:
    int bfs(vector<vector<int>>& grid){
        
        queue<pair<int,pair<int,int>>> q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int time = 0;
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
               int t = q.front().first;
               int i = q.front().second.first;
               int j = q.front().second.second;
               q.pop();
               
               int dx[4] = {0,-1,0,1};
               int dy[4] = {-1,0,1,0};
               
               for(int k = 0; k < 4; k++){
                   int row = i + dx[k];
                   int col = j + dy[k];
                   
                   if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1 ){
                       grid[row][col] = 2;   
                       q.push({t+1,{row,col}});
                       time = max(time ,t+1);
                   }
               }
        }
        
        // check if any fresh orange left
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }

    int orangesRot(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};