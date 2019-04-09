### 1000.Minimum Cost to Merge Stones:
One of the hardest problems of Leetcode. No wonder set as 1000-th problem.  
I try to implement DFS in contest, but failed.
The correct strategy is DP.  

 We need a 3-D DP array `dp[i][j][k]`, meaning minimum cost to merge `i` through `j` piles to `k` piles.  

 What we need is `dp[0][n - 1][1]`,  
 and `dp[0][n - 1][1] = dp[0][n - 1][K] + stones[0 ~ n - 1]`  
 How can we get `dp[0][n - 1][K]`?  
 `dp[0][n - 1][K] = min(dp[0][mid][1] + dp[mid + 1][n - 1][K - 1])`  
 Now, we found that we need `dp[i][j][K - 1]`, where `[i, j]` is within `[0, n -1]`.  

 So, we can conclude general transfer equation:
 ```C++
 dp[i][j][1] = dp[i][j][K] + stones[i ~ j]
 (K is uppercase)
 dp[i][j][k] = min(dp[i][mid][1], dp[mid + 1][j][k - 1])
 (mid is within [i, j))
 ```
 initial condition is `dp[i][j][j - i + 1] = 0`
 Another tough thing is handle edge:  
 `k` cannot be bigger than `K`. 
 `k` cannot be bigger than `j - i + 1`.
 Be careful about the int overflow, because not all cases(`[i][j][k]`) are considered.
 

 Time : O(n^3/K),  
 Space : O(n^2 * K).