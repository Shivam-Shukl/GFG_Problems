class Solution {
  public:
    void bfs(vector<vector<int>> &adj,vector<bool> &visited,vector<int> &v,int node){
  
        queue<int> q;
        visited[node] = true;
        q.push(node);
        
        while(q.size() >= 1){
            int frontnode = q.front();
            q.pop();
            v.push_back(frontnode);
            
            for(auto neigh : adj[frontnode]){
                if(visited[neigh] == false){
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n= adj.size();
        vector<bool> visited(n,false);
        vector<int> v;
       
        for(int i =0;i<adj.size();i++){
            if(visited[i] == false){
                bfs(adj,visited,v,i);
            }
        }
        return v;
    }
};