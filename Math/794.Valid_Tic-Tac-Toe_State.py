'''
Time: O(1),
Space: O(1).
'''

class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        x, o = 0, 0
        for s in board :
            x += s.count('X')
            o += s.count('O')
        
        if x == o : # no xxx
            for i in range(3) :
                if board[i] == "XXX" :
                    return False
                if board[0][i] == board[1][i] == board[2][i] == 'X':
                    return False
            if board[0][0] == board[1][1] == board[2][2] == 'X' :
                return False
            if board[0][2] == board[1][1] == board[2][0] == 'X' :
                return False
            return True
        
        elif x == o + 1: # no ooo
            for i in range(3) :
                if board[i] == "OOO" :
                    return False
                if board[0][i] == board[1][i] == board[2][i] == 'O':
                    return False
            if board[0][0] == board[1][1] == board[2][2] == 'O' :
                return False
            if board[0][2] == board[1][1] == board[2][0] == 'O' :
                return False
            return True
        
        else :
            return False