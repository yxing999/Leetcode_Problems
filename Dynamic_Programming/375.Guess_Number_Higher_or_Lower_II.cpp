/*
dp[i][j] means the money we need to guarantee a win from i to j.
we try to guess every number between i and j, in every guess we assume we are in worst luck,
so he money we need is k + max(dp[i][k - 1], dp[k + 1][i + t]).
Then we choose a smallest one as dp[i][j].

Time: O(n^3),
Space: O(n^2).
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int t = 1; t < n; t++)
        {
            for (int i = 1; i <= n - t; i++)
            {
                dp[i][i + t] = i + dp[i + 1][i + t]; 
                for (int k = i + 1; k < i + t; k++)
                {
                    dp[i][i + t] = min(dp[i][i + t], k + max(dp[i][k - 1], dp[k + 1][i + t]));
                }
            }
        }
        return dp[1][n];
    }
};