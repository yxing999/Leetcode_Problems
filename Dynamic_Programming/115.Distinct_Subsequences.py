'''
Basic DP problem about subsequence.

Time : O(m * n),
Space: O(m * n).
'''

class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        if m < n :
            return 0
        dp = [[0 for j in range(n + 1)] for i in range(m + 1)]
        for i in range(m + 1) :
            dp[i][0] = 1
        
        for j in range(1, n + 1) :
            for i in range(j, m + 1) :
                if s[i - 1] == t[j - 1] :
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
                else :
                    dp[i][j] = dp[i - 1][j]
        return dp[m][n]
        