class Solution {
  public:
    bool bfs(vector<vector<int>> &adj,vector<bool> &vis,int node){
        vis[node] = true;
        queue<pair<int,int>> q;
        q.push({node,-1});
        bool ans = false;
        
        while(!q.empty()){
            int frontnode = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto neigh : adj[frontnode]){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push({neigh,frontnode});
                }else if(neigh!= parent){
                    return true;
                }
            }
        }
     
        return ans;
    }
   
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        // how will you do it using bfs.
        // simply making an visited array and then checking if a repeated node occured or not.
        vector<bool> vis(V,false);
        vector<vector<int>> adj(V);
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = false;
     
        for(int i =0;i<V;i++){
            if(vis[i] == false){
                bool temp = bfs(adj,vis,i);
                if(temp==true)ans=true;
            }
        }
        return ans;
        
    }
};