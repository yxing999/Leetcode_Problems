'''
Follow up problem after House robber.
Solve it by divide and conquer, Dynamic programming.
Due to the connection of first and the last house,
The thief has two options:
1.start from 0 end at n-1;
2.start from 1 end at n.
So we create two DP array to calculate this two options, the choose the bigger one.

Time:O(n),
Space:O(n).
'''

class Solution:
    def rob(self, nums: 'List[int]') -> 'int':
        n=len(nums)
        if n==0:
            return 0
        if n==1:
            return nums[0]
        dp0,dp1=[0]*n,[0]*n
        dp0[0],dp0[1]=nums[0],max(nums[0],nums[1])
        dp1[1]=nums[1]
        for i in range(2,n-1):
            dp0[i]=max(dp0[i-2]+nums[i],dp0[i-1])
        for i in range(2,n):
            dp1[i]=max(dp1[i-2]+nums[i],dp1[i-1])
        return max(dp0[n-2],dp1[n-1])