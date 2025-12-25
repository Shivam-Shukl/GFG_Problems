class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int sum = INT_MIN;
        int prev = 0;
        for(int i =0;i<n;i++){
            prev = prev + arr[i];
            if(prev < 0){
                prev = 0;
            }else{
               sum = max(sum,prev); 
            }
            
            sum = max(sum,arr[i]);
        }
        return sum;
    }
};