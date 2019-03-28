'''
Basic DFS.
Loop on board, try to match word from (i, j).
Using backtracking strategy to avoid multiuse.

Time: O(m * n * l),
Space: O(1).
'''

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board :
            return False
        m, n = len(board), len(board[0])
        
        def DFS(i, j, word) -> bool:
            if len(word) == 0 :
                return True
            if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[0] :
                return False
            
            temp = board[i][j]
            board[i][j] = '#'
            for di, dj in [[-1, 0], [1, 0], [0, -1], [0, 1]] :
                ni, nj = i + di, j + dj
                if DFS(ni, nj, word[1: ]) :
                    return True
            board[i][j] = temp
            
            return False
            
        
        for i in range(m) :
            for j in range(n) :
                if DFS(i, j, word) :
                    return True
        
        return False