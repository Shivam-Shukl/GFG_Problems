

class Solution {
public:

    bool dfs(vector<vector<int>> &graph,vector<bool> &vis,vector<bool> &pathVis, vector<bool> &safe,int node){
        vis[node] = true;
        pathVis[node] = true;

        // point wali baat yeh hai ki agar terminal node ho toh true mark kar do 
        // aur latuate wakt check karo agar koi nahi mila toh true mark kar do 
        // iske liye bool function banana padega 

        bool cond = true;

        for(auto j : graph[node]){

            if(!vis[j]){
                if(!dfs(graph,vis,pathVis,safe,j)){
                    cond = false;
                }
            }else{
                if(pathVis[j]){
                    // cycle wali condtion 
                    cond = false;
                    break;
                }else if(!safe[j]){
                    cond = false;
                }
            }
        }

        if(cond) safe[node] = true;
        
        pathVis[node] = false;
        if (cond) return true;
        else return false;

    }
    vector<int> safeNodes(int V, vector<vector<int>>& edges){
        vector<vector<int>> graph(V);
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
        }
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<bool> pathVis(n,false);
        vector<bool> safe(n,false);

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                bool a = dfs(graph,vis,pathVis,safe,i);
            }
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};