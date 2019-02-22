class Solution:
    def canIWin(self, maxChoosableInteger: 'int', desiredTotal: 'int') -> 'bool':
        if maxChoosableInteger >= desiredTotal:
            return True
        if maxChoosableInteger * (maxChoosableInteger + 1) < 2 * desiredTotal:
            return False
        
        return self.DFS_with_Memo(maxChoosableInteger, desiredTotal, 0, {})
    
    def DFS_with_Memo(self, maxint, desired, status, Memo):
        if desired <= 0:
            return False
        
        if status in Memo:
            return Memo[status]
        
        for i in range(1, maxint + 1):
            if (status >> i) & 1 == 1:
                continue
            if self.DFS_with_Memo(maxint, desired - i, status | (1 << i), Memo) == False:
                Memo[status] = True
                return True;
        Memo[status] = False
        return False