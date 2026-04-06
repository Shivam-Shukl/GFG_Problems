class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjRev(V);
        vector<int> ind(V,0);
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjRev[v].push_back(u);
            ind[u]++;
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
            for(auto i : adjRev[frontNode]){
                ind[i]--;
                if(ind[i] == 0){
                    q.push(i);
                }
            }
        }
        return val;
        
    }
};