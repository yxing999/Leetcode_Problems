class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def cansplit(mid) : # whether can split into m parts smaller or equal to mid
            cnt = 0
            cur = 0
            for n in nums :
                cur += n
                if cur > mid :
                    cnt += 1
                    if cnt >= m :
                        return False
                    cur = n
            return True
        
        left = max(nums)
        right = sum(nums)
        
        while left < right :
            mid = left + (right - left) // 2
            if cansplit(mid) : # mid is big enough
                right = mid
            else :
                left = mid + 1
        
        return left