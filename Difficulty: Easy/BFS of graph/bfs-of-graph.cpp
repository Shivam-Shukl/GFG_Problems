class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void solve(int node,vector<int> &ans,vector<vector<int>> &adj,unordered_map<int,bool> &vis){
        
        queue<int> q;
        q.push(node);
        vis[node] = true;
        
        while(!q.empty()){
            
            int frontNode = q.front();
            for(int neigh: adj[frontNode]){
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
            ans.push_back(frontNode);
            q.pop();
        }
    }


    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        int n = adj.size();
        unordered_map<int,bool> vis;
        
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                solve(i,ans,adj,vis);
            }
        }
        return ans;
    }
};