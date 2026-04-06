class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        vector<int> ind(V, 0);

        // Build graph
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            ind[v]++;
        }

        queue<int> q;

        // Push nodes with indegree 0
        for(int i = 0; i < V; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        // BFS (Kahn's Algorithm)
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto neigh : adj[node]){
                ind[neigh]--;
                if(ind[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        // Cycle check
        if(ans.size() != V){
            return {}; // cycle exists
        }

        return ans;
    }
};