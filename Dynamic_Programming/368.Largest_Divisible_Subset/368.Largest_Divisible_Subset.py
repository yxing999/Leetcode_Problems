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