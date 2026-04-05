class Solution {
  public:
  
    void dfs(vector<vector<int>> &adj,stack<int> &st,vector<bool> &vis, int node){
        vis[node] = true;
        
        for(auto j : adj[node]){
            if(!vis[j]){
                dfs(adj,st,vis,j);
            }
        }
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<bool> vis(V,false);
        stack<int> st;
        for(int i =0;i<V;i++){
            if(!vis[i]){
                dfs(adj,st,vis,i);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            int top = st.top();
            ans.push_back(top);
            st.pop();
        }
        return ans;
    }
};