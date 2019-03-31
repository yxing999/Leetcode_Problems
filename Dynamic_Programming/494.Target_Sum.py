'''
Create a dictionary to memorize sum and corresponding number.
Loop on input nums, update dic at every index.
Considering same sum at the same index.

Time: O(2^n),
Space: O(2^n).
'''

class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        dic = {0: 1}
        
        for num in nums :
            update = {}
            for key in dic :
                update[key + num] = dic[key] + update.get(key + num, 0)
                update[key - num] = dic[key] + update.get(key - num, 0)
            dic = update
            
        return dic.get(S, 0)