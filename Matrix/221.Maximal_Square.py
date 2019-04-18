'''
We loop on the matrix from left-top to right-bottom, 
dp[i][j] represent maximal square edge end at (i, j),
it depends on the minimum among dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1].
But if matrix[i][j] == 0, dp[i][j] = 0.
Time: O(mn),
Space: O(mn).
'''

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        if m == 0:
             return 0
        n = len(matrix[0])
        dp = [[0 for j in range(n)] for i in range(m)]
        res = 0
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    dp[i][j] = int(matrix[i][j])
                else:
                    if matrix[i][j] == '1':
                        a = dp[i - 1][j - 1]
                        b = dp[i - 1][j]
                        c = dp[i][j - 1]
                        dp[i][j] = min(a, b, c) + 1
                res = max(res, dp[i][j])
                        
        return res**2