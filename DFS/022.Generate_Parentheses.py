'''
Very basic backtracking, just try to add '(' or ')',
')' can only be added when ')' is fewer than '('.

Time:O(2^n),
Space:O(n).
'''

class Solution:
    def generateParenthesis(self, n: 'int') -> 'List[str]':
        res=[]
        self.backtracking(n,res,'',0,0)
        return res
    def backtracking(self,n,res,temp,left,right):
        if len(temp)==2*n:
            res.append(temp)
            return
        if left<n:
            self.backtracking(n,res,temp+'(',left+1,right)
        if right<left:
            self.backtracking(n,res,temp+')',left,right+1)