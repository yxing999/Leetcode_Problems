### 473 Matchsticks to Square:
Two approaches to solve this problem, both by DFS.
Before DFS, we calculate the sum of input array, 
to make sure it is multiple of 4. Get the target edge length.

#### Solution 1:
Create an array `visited` to remember the matchsticks we used.  
Build the square side one by one:  
For every edge, loop on the input `nums`,  
if current matchsticks is not used and it can be added to current edge(less than target length after adding), add it.  
when finish one edge, start a new edge, loop on `nums` from 0.  
If we finish 3 edges, the rest matchsticks must be able to form an edge. return Ture.  
If no Ture is returned after the DFS, return False.

#### Solution 2:
Create a List with 4 zeros, representing length of 4 edges.  
Loop on the input nums, try to add it to every element of the List(Make sure it doesn't exceed target edge length).  
If we can add all matchsticks, return Ture.  
If we cannot, return False.  
  
Time: I don't Know, exponential level anyway. 
Space: O(n)