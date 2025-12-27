// User function Template for C++

class Solution {
  public:
    bool prime(int n){
    // cout<<"Yes"<<endl;
        if(n == 1) return false;
        for(int i = 2;i*i<=n;i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    vector<int> primeRange(int M, int N) {
        vector<int> ans;
    
        for(int i = M;i<= N;i++){
       
            if(prime(i)== true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};