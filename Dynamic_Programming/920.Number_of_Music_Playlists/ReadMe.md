### 920.Number of Music Playlists:
This is a very good problem about Dynamic Programming.  

For the number of playlists of length l, including n kinds of  songs, we can get it from that of length (l - 1).  
We use `dp[n][l]` to represent length l playlist including n kinds of songs.  
There are two cases of (l - 1) length playlist :  
1.  
It contains (n - 1) kinds of songs:  
This (n - 1) can be any combination of n, so there are n kinds of 
`dp[n-1][l-1]`. What we should do is add the remaining kind of song at the l-th position, we have n choices in total.  
2.  
It already contains n kinds of songs:
We can add any songs at l-th position, as long as it is different from the previous k songs. They previous k songs are all different(otherwise it will violate rule 2), so we have (n - k) choices.  
  
The transfer equation based on analysis above:  

`dp[n][l] = dp[n - 1][l - 1] * n + dp[n][l - 1] * (n - k)`  
  
When `n == l`, `dp[n][l] = n!`.  
This is initial condition for every n(n > K).

Time: O((N - K) * (L - K))  
Space: O(N * L)
