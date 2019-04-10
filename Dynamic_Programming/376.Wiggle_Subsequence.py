'''
up marks current max wiggle subsequence with up end, 
down marks current max wiggle subsequence with down end.
they are like two pointers.

loop on input nums, 
encounter up pair, up = down + 1,
encounter down pair, down = up + 1.

Time: O(n),
Space: O(1).
'''

class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0 : 
            return 0
        
        up, down = 1, 1
        for i in range(1, n) :
            if nums[i] > nums[i - 1] :
                up = down + 1
            elif nums[i] < nums[i - 1] :
                down = up + 1
        
        return max(up, down)
        
