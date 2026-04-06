class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> ind(V,0);
        
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            ind[v]++;
        }
        
        queue<int> q;
        for(int i =0;i<V;i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        vector<int> val;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            val.push_back(frontNode);
            for(auto u : adj[frontNode]){
                ind[u]--;
                if(ind[u] == 0){
                    q.push(u);
                }
            }
            
        }
   
        
        return val.size() != V;
   
    }
};