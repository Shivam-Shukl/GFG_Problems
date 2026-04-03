class Solution {
  public:
    bool bfs(vector<vector<int>> &adj,vector<bool> &vis,int node){
        vis[node] = true;
        queue<pair<int,int>> q;
        q.push({node,-1});
        
        while(!q.empty()){
            int frontNode = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto neigh : adj[frontNode]){
                if(!vis[neigh]){
                    q.push({neigh,frontNode});
                    vis[neigh] = true;
                }else{
                    if(neigh != parent ){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
       
        vector<bool> vis(V,false);
        vector<vector<int>> adj(V);
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(bfs(adj,vis,i)){
                    return true;
                }
            }
        }
        
        return false;
    }
};