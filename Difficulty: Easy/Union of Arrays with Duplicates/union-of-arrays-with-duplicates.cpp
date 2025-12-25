class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,bool> mp;
        for(int i =0;i<a.size();i++){
            if(mp.find(a[i]) == mp.end()){
                mp[a[i]] = true;
            }
        }
        for(int i =0;i<b.size();i++){
            if(mp.find(b[i]) == mp.end()){
                mp[b[i]] = true;
            }
        }
        vector<int> ans;
        for(auto it = mp.begin();it != mp.end();it++){
            ans.push_back(it->first);
        }
        return ans;
    }
};