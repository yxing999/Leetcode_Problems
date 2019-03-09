### 133.Clone Graph:
The key to solve this problem is:
Build a hash table to connect original node and cloned node, 
because we will use previous nodes when cloning the graph. 
  
We can do it by either iteration or recursion.
For the iteration, build all nodes first, and then connect them.  
  
Time: O(n),
Space: O(n).
