class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if n < k:
            return False
        total = sum(nums)
        if total % k != 0:
            return False
        target = total // k
        visited = [0] * n
        
        def DFS(pos, cursum, k):
            if k == 1:
                return True
            if cursum == target:
                return DFS(0, 0, k-1)
            if cursum > target:
                return False
            
            for i in range(pos, n):
                if not visited[i]:
                    visited[i] = 1
                    if DFS(i + 1, cursum + nums[i], k):
                        return True
                    visited[i] = 0
            return False
        return DFS(0, 0, k)