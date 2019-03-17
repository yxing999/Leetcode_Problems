### 996.Number of Squareful Array:
Make use of backtracking to find possible permutation.  
Check the sum of current number and last number of temporary array, 
if it is squareful, push it back, go on DFS.  
When `temp`'s size reaches n, we find a result, res plus one.  

Time: O(2^n)
Space: O(n).