'''
If you implement straight forward DFS, the run time could be very slow.
Considering at index i, there may be some result with the same sum,
So we memorize them, when we back here, we use it directly.

For the memo cache: key is (index, sum of rest nums), value is the number.

This problem serves as a good material for DFS with memo, but not backtracking.

Time: O(2^n)
Space: O(2^n)
'''

class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        cache = {}
        
        def DFS(i, rest_sum) :
            if (i, rest_sum) not in cache :
                r = 0
                if i == len(nums) :
                    if rest_sum == 0 :
                        r = 1
                    return r
                
                r = DFS(i + 1, rest_sum - nums[i]) + DFS(i + 1, rest_sum + nums[i])
                cache[(i, rest_sum)] = r
            
            return cache[(i, rest_sum)]
        
        return DFS(0, S)