### 679.24 Game:
Find all permutations of four digits.  
For every permutation, try to add operator `+`, `-`, `*`, `/` at possible space between two digits.  
We add one operator at one step, the position order we add plays the role of bracket, because we calculate the result at every layer.  
The array will become 4 -> 3 -> 2 -> 1, if the result is 24, just return true.  
  
Time: O(2^4 * 12 * 8 * 4),  
Space: O(1).
