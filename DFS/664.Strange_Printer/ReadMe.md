### 664.Strange Printer:
A problem about DFS with memo.  
This is also a good template for problem about string printer.

`memo[start][end]` represents minimum turn to print from start to end.  
For every `i` where `start <= i < end`, if `s[i] == s[end]`, we can print `start` to `i` and `i + 1` to `end - 1`, and see whether it is optimized. Becasue `s[i]` and `s[end]` can be printed at the same time.  

For example:
`axxxxaxxxa`  
we can print `a` and then `xxxxaxxx`,  
or we can print `axxxxa` and `xxx`.  

A trick for this problem is, we can slim the input string first.  
`aaabbbccc` -> `abc`.  
This will save a lot of time.  

Time: O(n^3),  
Space: O(n^2).