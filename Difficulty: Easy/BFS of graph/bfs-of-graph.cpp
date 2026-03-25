class Solution {
  public:
    void bfs(vector<vector<int>> &adj,vector<bool> &vis,vector<int> &v,int node){
        vis[node] = true;
        queue<int> q;
        q.push(node);
        v.push_back(node);
        while(!q.empty()){
            int frontnode = q.front();
            q.pop();
            for(auto neigh : adj[frontnode]){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push(neigh);
                    v.push_back(neigh);
                }
            }
        }
     
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n= adj.size();
        vector<bool> visited(n,false);
        vector<int> v;
       
        for(int i =0;i<adj.size();i++){
            if(visited[i] == false){
                bfs(adj,visited,v,i);
            }
        }
        return v;
    }
};