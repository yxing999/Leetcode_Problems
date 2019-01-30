'''
Basic DP problem.
Create four integet, remember current max, current min, previous max and previous min.
At index i, we need to get the max subarray ending at i, min subarray ending at i.
So, we calculate 3 numbers: nums[i],nums[i]*premax,nums[i]*premin
choose the maximum as curmax, choose the minimum as curmin.
Update res at every index i.
Time:O(n)
Space:O(1)
'''

class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        if n==0:
            return 0
        curmax=premax=nums[0]
        curmin=premin=nums[0]
        res=nums[0]
        
        for i in range(1,n):
            curmax=max(nums[i],nums[i]*premax,nums[i]*premin)
            curmin=min(nums[i],nums[i]*premax,nums[i]*premin)
            res=max(res,curmax)
            premax=curmax
            premin=curmin
        
        return res