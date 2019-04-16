### 798.Smallest Rotation with Highest Score:
For index `i`, if we rotate at index `k`, where will it go?  
1. `i < k`:  
   `new_i = i + n - k`,  
2. `i >= k`:
   `new_i = i - k`.

To get point, `A[i]` should less than or equal to `new_i`, `A[i] <= new_i`.  
Import this equation into above equations, we get two inequalities:  

1. `k <= i - A[i]`(i - A[i] >= 0)
2. `i < k <= i + n - A[i]`  

which means, for index `i`, the `k` meeting the above inequalities can make it get 1 point.  

The strategy to find smallest k to get highest scores are as follows:  
Create an array, plus one at `0`, minus one at `i - A[i] + 1`, plus one at `i + 1`, minus one at `i + n - A[i] + 1`. Which means, we can get 1 point in the range  
`[0, i - A[i]]`,  
`[i + 1, i + n - A[i]]`.  
Loop on this array from left to right, get the highest score with its index k.  

Time: O(n),\
Space: O(n).  