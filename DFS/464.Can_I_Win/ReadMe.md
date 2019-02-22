### 464.Can I Win:
Good problem about DFS with memo. Base on a game context.  

Two key structres of this problem:  
1.An int number `status`.  
To memorize used integer.  

2.A map (or Dict) `Memo`.  
To memorize result from current status.  
  
The DFS with memo process:  
1.Check Memo, if Memo[status] exists, return it.  
2.Try all available integer, if the result is false after one of it,
Memo[status] must be true, return it.  
3.If there is no false returned in step 2, Memo[status] is uncertain,
which means rival has options to win.  
So, Memo[status] is false.

Time:O(2^n),  
Space:O(1).
