# Solution 1
class Solution:
    def makesquare(self, nums: 'List[int]') -> 'bool':
        perimeter = sum(nums)
        n = len(nums)
        if n < 4 or perimeter % 4 != 0:
            return False
        visited = [0] * n
        target = perimeter // 4
        
        def DFS(pos, fulledge, curlen):
            if fulledge == 3:
                return True
            if curlen > target:
                return False
            if curlen == target:
                return DFS(0,fulledge + 1, 0)
            
            for i in range (pos, n):
                if visited[i] == 1: continue
                visited[i] = 1
                if DFS(i + 1, fulledge, curlen + nums[i]):
                    return True
                visited[i] = 0
            return False
        return DFS(0,0,0)


# Solution 2
class Solution:
    def makesquare(self, nums: 'List[int]') -> 'bool':
        if len(nums) == 0:
            return False
        perimeter = sum(nums)
        if perimeter % 4 != 0:
            return False
        res = [perimeter // 4] * 4
        nums.sort(reverse = True)
        
        def DFS(pos):
            if pos == len(nums):
                return True
            for i in range(4):
                if res[i] - nums[pos] >= 0:
                    res[i] -= nums[pos]
                    if DFS(pos + 1): return True
                    res[i] += nums[pos]
            return False
        
        return DFS(0)