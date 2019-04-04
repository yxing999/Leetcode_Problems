'''
Try to multiply 2 or 3 or 5 from a previous ugly number.
choose the minimum one as current one, until n.

Time: O(n)
Space : O(n)
'''

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1 for i in range(n)]
        last2, last3, last5 = 0, 0, 0
        
        for i in range(1, n) :
            cur2, cur3, cur5 = dp[last2] * 2, dp[last3] * 3, dp[last5] * 5
            dp[i] = min(cur2, cur3, cur5)
            
            if dp[i] == cur2 : last2 += 1
            if dp[i] == cur3 : last3 += 1
            if dp[i] == cur5 : last5 += 1
        
        return dp[-1]