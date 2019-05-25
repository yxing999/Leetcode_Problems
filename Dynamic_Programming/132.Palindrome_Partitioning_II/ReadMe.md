### 132.Palindrome Partitioning II:

Loop on the input string `s`.  
At index `i`, loop `j` from index `0` to `i`.  

if substring s[j:i] is a palindrome,  
`dp[i + 1] = min(dp[i + 1], dp[j] + 1)`.

We use another 2D dp array to memorize palindrome substrings, and integrate these two parts into one 2D for loop.

Time: O(n^2),\
Space: O(n^2).