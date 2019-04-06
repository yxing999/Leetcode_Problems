'''
Maintain a 2D array,
Loop on the input string, try to add current str to dp[i][j] if it can be added.
(if dp[i - zero][j - one] is initial case or updated already.)

return the biggest number in this 2D array.(Not dp[m][n])

Time: O(mnk), 不严谨，差不多吧
Space: O(mn)
'''
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0 for i in range(n + 1)] for j in range(m + 1)]
        res = 0
        
        for s in strs :
            zero, one = s.count('0'), s.count('1')
            for i in range(m - zero, -1, -1) :
                for j in range(n - one, -1, -1) :
                    if i == 0 and j == 0 or dp[i][j] != 0 :
                        dp[i + zero][j + one] = max(dp[i + zero][j + one], dp[i][j] + 1)
                        res = max(res, dp[i + zero][j + one])
                        
        return res