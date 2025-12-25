class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        // what is your idea behind it how will you deal with the question.
        // i'm be like prevouly i was d
        int n = arr.size();
        int sum = 0;
        for(int i =0;i<k;i++){
            sum += arr[i];
        }
        int ans = sum;
        for(int i = 1;i<=n-k;i++){
            sum -= arr[i-1];
            sum += arr[k+i-1];
            ans = max(ans,sum);
        }
        return ans;
    }
};