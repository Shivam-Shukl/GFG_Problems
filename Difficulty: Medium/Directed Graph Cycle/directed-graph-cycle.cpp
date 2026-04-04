class Solution {
  public:
  
    bool dfs(vector<vector<int>> &adj,vector<bool> & vis,vector<bool> & pathVis,int node){
        vis[node] = true;
        
        for(auto j : adj[node]){
            if(!vis[j]){
                pathVis[node]= true;
                if(dfs(adj,vis,pathVis,j)) return true;
                pathVis[node] = false;
            }else{
                if(pathVis[j]){
                    return true;
                }
            }
            
        }
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> vis(V,false);
        vector<bool> pathVis(V,false);
        
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,pathVis,i)){
                    return true;
                }
            }
        }
        
        return false;
    }
};