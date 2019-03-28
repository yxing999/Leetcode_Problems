'''
Construct the Magical String following the rule.
Set two pointers:
One points to the tail of origin string,
Another points(cur) to the tail of string after concatenating(some index of origin string actually).

On every step, add str[cur] elements on tail of origin string, element should be different from tail of 
origin string(1->2, 2->1).

Time: O(n),
Space: O(n).
'''

class Solution:
    def magicalString(self, n: int) -> int:
        str = [1, 2, 2]
        cur = 2
        
        while len(str) < n :
            val = 3 - str[-1]
            str.extend(str[cur] * [val])
            cur += 1
        
        return str[:n].count(1)