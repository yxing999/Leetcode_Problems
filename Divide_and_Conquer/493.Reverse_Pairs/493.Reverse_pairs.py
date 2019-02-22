class Solution:
    def reversePairs(self, nums: 'List[int]') -> 'int':
        return self.mergesort(nums, 0, len(nums) - 1)
    def mergesort(self, nums:'List[int]', left, right) -> 'int':
        if left >= right:
            return 0
        mid = left + (right - left) // 2
        res = self.mergesort(nums, left, mid) + self.mergesort(nums, mid + 1, right)
        
        j = mid + 1
        for i in range(left, mid + 1):
            while j <= right and nums[i] > 2 * nums[j]:
                j += 1
            res += j - (mid + 1)
        nums[left: right + 1] = sorted(nums[left: right + 1])
        '''
        L, R = nums[left: mid + 1], nums[mid + 1: right + 1]
        p, q = 0, 0
        for k in range(left, right + 1):
            if q == len(R) or (p < len(L) and L[p] < R[q]):
                nums[k] = L[p]
                p += 1
            else:
                nums[k] = R[q]
                q += 1
        '''
        return res