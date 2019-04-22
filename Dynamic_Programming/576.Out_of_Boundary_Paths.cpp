/*
dp[p][q][k] means the number of paths from (p, q) in k steps.

Time: O(m*n*N),
Space:O(m*n*N).
*/

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int dp[51][51][51];
        int mod = 1e9 + 7;
        for (int k = 1; k <= N; k++)
        {
            for (int p = 0; p < m; p++)
            {
                for (int q = 0; q < n; q++)
                {
                    long up, down, left, right;
                    
                    if (p == 0) up = 1;
                    else up = dp[p - 1][q][k - 1];
                    
                    if (p == m - 1) down = 1;
                    else down = dp[p + 1][q][k - 1];
                    
                    if (q == 0) left = 1;
                    else left = dp[p][q - 1][k - 1];
                    
                    if (q == n - 1) right = 1;
                    else right = dp[p][q + 1][k - 1];
                    
                    dp[p][q][k] = (up + down + left + right) % mod;
                }
            }
        }
        return dp[i][j][N];
    }
};