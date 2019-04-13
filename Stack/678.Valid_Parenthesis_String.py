'''
A popular strategy to check validation of parenthesis is tracking number of left parenthesis l.
We loop on string, add 1 to l when we meet '(', minus 1 when meet ')',
l should always be non-negative and 0 in the end.

For this problem, '*' can broaden the possible range of l,
the string is valid as long as low is 0 in the end.

Time: O(n),
Space: O(1).
'''

class Solution:
    def checkValidString(self, s: str) -> bool:
        low, high = 0, 0
        
        for c in s :
            if c == '(' :
                low += 1
                high += 1
            elif c == ')' :
                if high == 0 :
                    return False
                low = max(0, low - 1)
                high -= 1
            else :
                low = max(0, low - 1)
                high += 1
        
        return low == 0