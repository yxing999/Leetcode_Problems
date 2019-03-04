'''
A n1 length string multiplies an n2 length string can result a at most (n1 + n2) length string.
Create an array of (n1 + n2) size, add the contribution digit by digit.

Time: O(n1 * n2),
Space: O(n1 + n2).
'''

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0" :
            return "0"
        
        result = [0] * (len(num1) + len(num2) + 1)
        pos = len(result) - 1
        
        for n1 in reversed(num1) :
            temp = pos
            for n2 in reversed(num2) :
                result[temp] += int(n1) * int(n2)
                result[temp - 1] += result[temp] // 10
                result[temp] %= 10
                temp -= 1
            pos -= 1
        
        p = 0
        while p < len(result) and result[p] == 0 :
            p += 1
        
        return "".join(map(str, result[p: ]))