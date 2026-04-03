class Solution {
  public:
    void bfs(vector<vector<int>> &adj,vector<int> &ans,int node,vector<bool> &vis){
        vis[node] = true;
        queue<int> q;
        ans.push_back(node);
        q.push(node);
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto neigh : adj[frontNode]){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push(neigh);
                    ans.push_back(neigh);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int> ans;
        vector<bool> vis(n,0);
        for(int i =0;i<n;i++){
            if(!vis[i]){
                bfs(adj,ans,i,vis);
            }
        }
        return ans;
    }
};