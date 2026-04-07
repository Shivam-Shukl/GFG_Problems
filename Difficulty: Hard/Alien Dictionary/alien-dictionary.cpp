class Solution {
  public:
    
    string topoSort(vector<vector<int>> &adj, unordered_map<char, int> &mp, vector<int> &ind){
        int V = adj.size();
        vector<int> ans;
        queue<int> q;

        for(int i = 0; i < V; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(auto i : adj[frontNode]){
                ind[i]--;
                if(ind[i] == 0){
                    q.push(i);
                }
            }
        }

        if(ans.size() != V){
            return "";
        } else {
            string st = "";
            
            // reverse mapping
            vector<char> rev(mp.size());
            for(auto &it : mp){
                rev[it.second] = it.first;
            }

            for(int i = 0; i < ans.size(); i++){
                st.push_back(rev[ans[i]]);
            }
            return st;
        }
    }

    string findOrder(vector<string> &words) {
        
        set<char> st;
        for(auto &w : words){
            for(auto c : w){
                st.insert(c);
            }
        }
        
        unordered_map<char, int> mp;
        int val = 0;
        
        for(auto it = st.begin(); it != st.end(); it++){
            mp[*it] = val++;
        }
  
        int n = st.size();
        
        // ✅ use set to avoid duplicate edges
        vector<set<int>> adjSet(n);
        vector<int> ind(n, 0);
        
        for(int i = 0; i < words.size() - 1; i++){
            string st1 = words[i];
            string st2 = words[i + 1];
            
            int m = st1.size();
            int p = st2.size();
            int j = 0;
            
            while(j < m && j < p && st1[j] == st2[j]){
                j++;
            }
  
            if(j == p && m > p){
                return "";
            }
            
            if(j < m && j < p){
                int a = mp[st1[j]];
                int b = mp[st2[j]];
                
        
                if(adjSet[a].find(b) == adjSet[a].end()){
                    adjSet[a].insert(b);
                    ind[b]++;
                }
            }
        }
        
        // convert set → vector
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(auto j : adjSet[i]){
                adj[i].push_back(j);
            }
        }
        
        return topoSort(adj, mp, ind);
    }
};