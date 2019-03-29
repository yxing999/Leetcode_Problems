### 114.Flatten Binary Tree to Linked List:

This problem can be solved by recursion or iterative.  

The key process in both solution is:  
Connect the biggest node of left tree to the original right tree. The biggest node is the right most node.   
Set a temporary pointer pointing to root, move it to the right child until it is a leaf, this pointer is the biggest node of this tree.  
  
Time: O(n),\
Space: O(1).