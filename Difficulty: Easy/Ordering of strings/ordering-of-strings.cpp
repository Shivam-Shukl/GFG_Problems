

class Solution {
  public:
    bool check(string a, string b){
        int n = a.size(),m=b.size();
        int i = 0,j= 0;
        while(i<n && j<m){
            if(a[i] < b[i]){
                return true;
            }else if(a[i] > b[i]){
                return false;
            }
            i++,j++;
        }
        if(n > m) return false;
        else return true;
    }
    vector<string> orderString(string s[], int n) {
        // code here.
        string small = s[0],l= "";
        for(int i = 0;i<n;i++){
            if(check(s[i],small)){
                small = s[i];
            }
            if(!(check(s[i],l))){
                l= s[i]; 
            }
        }
        vector<string> ans;
        ans.push_back(small);
        ans.push_back(l);
        return ans;
    }
};