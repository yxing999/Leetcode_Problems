### 51.N-Queens:
Very classic problem: 8-Queens.  
But it is not hard.
Just use backtracking and trick for diagonal.  
  
For the diagonal from top-left to bottom right, 
the difference of every x and y is a constant.  
For the diagonal from top-right to bottom-left,
the sum of every x and y is a constant.  
  
From 1-th row to N-th row, we try to put a 'Q' at (x, y) 
where there is no overlap on 8 direction with other 'Q's.  
If we reach the bottom, we find a result, put it into result.  
  
Time: I don't know  
Space: O(n).
