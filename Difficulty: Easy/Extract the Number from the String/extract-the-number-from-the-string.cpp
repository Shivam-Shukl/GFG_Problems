// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
        long long ans  = -1;
        
        int n = s.size();
        int i =0;
        while(i<n){
            
            if(s[i] >= '1' && s[i] <= '9'){
                long long val = 0;
                bool isNine = false;
                while(s[i] >= '0' && s[i] <= '9')
                {
                  
                    if(s[i]=='9'){
                        isNine = true;
                    }
                    
                    val = val*10 + (s[i] -'0');

                    i++;
                }
      
            
                if(isNine == false){
                    ans = max(val,ans);
                }
            }else{
                 i++;
            }
            
            
        }
        return ans;
        
    }
};