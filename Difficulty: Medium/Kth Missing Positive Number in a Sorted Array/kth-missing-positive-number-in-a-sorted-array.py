class Solution:
    def kthMissing(self, arr, k):
        # code here
        length = len(arr)
        last = arr[length - 1]

        cnt = 0
  
        lst = [True] * (last + 1)
        
        for ele in arr:
            lst[ele] = False

        ans = 0
  
        for i in range(1,len(lst)):
            if lst[i] is True:
                cnt += 1
       
                if cnt == k:
                    ans = i
                    break
            else:
                ans = i
  
        while cnt != k:
            ans += 1
            cnt += 1
        
        return ans
