### 493.Reverse Pairs:
For two parts of the array,  
1.we can find all possible reverse pairs in O(n) if these two parts are sorted respectively.  
2.The order of elements dosen't affect the number of reverse pairs between this two parts.  
  
  
So, we come up with a strategy:  
Start from smallest parts, count the reverse pairs, sort them, 
then move to larger parts which merge these smaller parts.  
`[0,1][2,3][4,5][6,7]...[n-2,n-1]` ->  
`[0,1,2,3][4,5,6,7]...[n-4,n-3,n-2,n-1]` ->  
`[0,1,...,n/2][n/2+1,...,n-2,n-1]`.  

This is kind of merge sort. only plus counting process on every step.  
Also, this is a very typical divide and conquer algorithm.  
  
Time: O(nlogn),  
Space:O(n).




