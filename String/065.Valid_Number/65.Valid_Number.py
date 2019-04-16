class Solution:
    def isNumber(self, s: str) -> bool:
        state = [{},
                {"blank": 1, "sign": 2, "digit": 3, "dot": 4}, # s1
                {"digit": 3, "dot": 4}, # s2
                {"digit": 3, "dot": 5, "e": 6, "blank": 9}, # s3
                {"digit": 5}, # s4
                {"digit": 5, "e": 6, "blank": 9}, # s5
                {"sign": 7, "digit": 8}, # s6
                {"digit": 8}, # s7
                {"digit": 8, "blank": 9}, # s8
                {"blank": 9}] # s9
        
        cur_state = 1
        for c in s :
            if c == ' ' :
                c = "blank"
            elif c == '+' or c == '-' :
                c = "sign"
            elif c == '.' :
                c = "dot"
            elif c == 'e' :
                c = "e"
            elif c >= '0' and c <= '9' :
                c = "digit"
            
            if c not in state[cur_state].keys() :
                return False
            cur_state = state[cur_state][c]
            
        if  cur_state not in [3, 5, 8, 9] : # end state
            return False
        return True