### 1001.Grid Illumination:
A problem to practice diagonal handling in a matrix.  
  
For the diagonal from top-left to bottom right, 
the difference of every x and y is a constant.  
For the diagonal from top-right to bottom-left,
the sum of every x and y is a constant.  
  
Every lamp contributes to row, column, diagonal and rdiagonal.  
So, we build four hash maps to record every lamps contribution.  
On each query, we check this four hash maps to find whether a lamp is illuminating it.  
After query, check adjacent cell, if there is a lamp, remove it from four hash maps.  
  
Time: O(n),  
Space: O(n).   