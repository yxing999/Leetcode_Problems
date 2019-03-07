'''
First we find the target sum of two subsets.
Then we build an array dp.
dp[i] represents whether we can find a subset with sum i,
apparently, the size of dp is (target + 1).

Loop on input nums, every num in nums can make dp[k + num] true if dp[k] is true.
So, for every num, we update dp, from index target to num.

Time:O(target),
Space:O(target).
'''

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0 :
            return False
        target = total // 2
        dp = [False] * (target + 1)
        dp[0] = True
        
        for num in nums :
            for i in range(target, num - 1, -1) :
                dp[i] = dp[i] or dp[i - num]
        
        return dp[target]