'''
Sort the input nums, because if a can be divided by b, a can be divided by b's divisors.
Create a dp array, each element is a pair, containing last index of divisor and length of divisible subset until now.
At index i, scan all previous elements of dp:
Find the divisible numbers and choose the largest one, update dp, record the largest subset until now in maxlen.
maxlen records the index.
After that, insert the largest subset into res.

Time:O(n^2),
Space:O(n).
'''

class Solution:
    def largestDivisibleSubset(self, nums: 'List[int]') -> 'List[int]':
        res = []
        if not nums:
            return res
        nums.sort()
        n = len(nums)
        length = [1]*n
        pre = [-1]*n
        maxlen = 0
        for i in range(1,n):
            for j in range(i-1,-1,-1):
                if nums[i]%nums[j] == 0 and length[i] < length[j] + 1:
                    length[i] =  length[j] + 1
                    pre[i] = j
                if length[i] > length[maxlen]:
                    maxlen = i
        
        while pre[maxlen] != -1:
            res.insert(0,nums[maxlen])
            maxlen = pre[maxlen]
        res.insert(0,nums[maxlen])
        return res