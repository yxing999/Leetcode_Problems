### 698.Patition to K Equal Sum Subsets:
This is a general version of LC 473.  
This solution can serve as a template for all similar problem.  
  
Create an array `visited` to remember the elements we used.  
Build the subsets one by one:  
For every subset, loop on the input `nums`,  
If current element is not used and it can be added to current subset(less than target after adding), add it.  
when finish one subset, start a new subset, loop on `nums` from 0.  
If we finish `k-1` edges, the rest elements must be able to form an target subset. return Ture.  
If no Ture is returned after the DFS, return False.  
  
Sort the input array in descending order can speed up the runtime.  

Time: I don't Know, exponential level anyway.  
Space: O(n)
