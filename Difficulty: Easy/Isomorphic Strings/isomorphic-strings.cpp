class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        unordered_map<char,char> mp;
        vector<bool> vis(26,false);
        
        for(int i =0;i<s1.size();i++){
            char ch1 = s1[i],ch2 = s2[i];
            if(mp.find(ch2) != mp.end()){

                if(mp[ch2] != ch1){
                    return false;
                }
            }
            else{
                if(!vis[ch1-'0']){
                    mp[ch2] = ch1;
                    vis[ch1-'0'] = true;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};