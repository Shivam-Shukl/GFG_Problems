class Solution {
  public:
    void dfs(vector<vector<int>> &adj,vector<bool> &vis,int node,vector<int> &ans){
        
        ans.push_back(node);
        
        
        for(auto neigh : adj[node]){
            if(vis[neigh] == false){
                vis[neigh] = true;
                dfs(adj,vis,neigh,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> vis(n,0);
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(vis[i] == false){
                vis[i] = true;
                dfs(adj,vis,i,ans);
            }
        }
        return ans;
    }
};