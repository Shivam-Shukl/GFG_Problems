
from typing import List


class Solution:
    def maxTip(self, n : int, x : int, y : int, arr : List[int], brr : List[int]) -> int:
        # code here
        diff=[]
        for i in range(n):
            diff.append((abs(arr[i]-brr[i]),i))
        diff.sort(reverse=True)
        total_tip=0
        a_orders=0
        b_orders=0
        for d, i in diff:
            if (arr[i] >= brr[i] and a_orders < x) or b_orders >= y:
                total_tip += arr[i]
                a_orders += 1
            else:
                total_tip += brr[i]
                b_orders += 1
    
        return total_tip

