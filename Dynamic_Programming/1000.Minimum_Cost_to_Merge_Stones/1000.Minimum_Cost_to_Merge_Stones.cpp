class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if (K != 2 && n % (K - 1) != 1) return -1;
        
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + stones[i - 1];
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K + 1, INT_MAX)));
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j - i + 1 > K) break;
                dp[i][j][j - i + 1] = 0; 
            }
        }
        
        for (int t = 1; t < n; t++) {
            for (int i = 0; i < n - t; i++) {
                for (int k = 2; k <= K; k++) {
                    if (k > t + 1) break;
                    for (int mid = i; mid < i + t; mid++) {
                        if (dp[i][mid][1] != INT_MAX && dp[mid + 1][i + t][k - 1] != INT_MAX)
                            dp[i][i + t][k] = min(dp[i][i + t][k], dp[i][mid][1] + dp[mid + 1][i + t][k - 1]);
                    }
                }
                if (dp[i][i + t][K] != INT_MAX)
                    dp[i][i + t][1] = dp[i][i + t][K] + sum[i + t + 1] - sum[i];
            }
        }
        return dp[0][n - 1][1];
    }
};