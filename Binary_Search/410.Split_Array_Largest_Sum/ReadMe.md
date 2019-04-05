### 410.Split_Array_Largest_Sum :
It is so tricky to solve this problem by binary search!  
  
For an input nums, no matter what m is, the biggest result is sum of nums elements, the smallest result is max element of nums.  
In other words, the result is in range `[max(nums), sum(nums)]`.

To be more precise, the result is range `[left, right]`, who belongs to `[max(nums), sum(nums)]`.  

Now, our task is find the minimum result(left edge) in this range by binary search:  
  
`mid = left - (right - left) / 2`  
If nums can be split to `m` parts, with every part's sum no bigger than `mid`, that means `mid` is big enough. we move the `right` to `mid`.  
If not, which means `mid` is too small, we move `left` to `mid + 1`.  

Time: O(n * log(L)), L is `(sum - max)`  
Space: O(1).