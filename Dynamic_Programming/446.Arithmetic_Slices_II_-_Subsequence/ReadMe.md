record structure: <index, <dif, count>>.  
At index i dif with index j, the number of subsequences that satisfy the requirement is `record[j][dif]`.  
`record[i][dif]++` means the new subsequence [j, i], whose length is 2.

A trick is:  
```C++
if ((long)A[i] - A[j] > INT_MAX || (long)A[i] - A[j] <= INT_MIN) continue;
```
Because subsequences with length more than 3 cannot have such big interval.

Time : O(n^2),  
Space: O(n^2).