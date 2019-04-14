### 629.K Inverse Pairs Array:
2D DP problem, additional trick to reduce the time complexity.  
`dp[i][j]` means from `1` to `i`, `j` inverse pairs. So, we want `dp[n][k]`.  
We can get `dp[i][j]` from `dp[i - 1][]`:  
we can insert `i` at `i - 1` to `dp[i - 1][j]`,  
or insert `i` at `i - 2` to `dp[i - 1][j - 1]`,   
......  
insert `i` at `0` to `dp[i - 1][j - (i - 1)]`.  
The transfer equation:  
`dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]+ ... + dp[i - 1][max(0, j - (i - 1))]`  

The time complexity for this strategy is O(nk^2), it got TLE when k is large.  

After reviewing the transfer equation:  
`dp[i - 1][j - 1]+ ... + dp[i - 1][max(0, j - (i - 1))]` is just like `dp[i][j - 1]`.  
What we should handle additionally is edge case:  
If `j < i`, `dp[i - 1][max(0, j -(i - 1))]` is `dp[i - 1][0]`, we can cover all elements from `dp[i][j - 1]`, so:  

`dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`  

Otherwise, we should throw the `dp[i - 1][(j - 1) - (i - 1)]` from `dp[i][j - 1]`, so:  

`dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - i]`  

Time: O(nk),\
Space: O(nk).