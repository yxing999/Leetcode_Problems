'''
At index i, traverse back from (i - 1), 
If we find an index j, where i % j == 0, that means we can get i from j by pasting (i / j) - 1 times,
plus the copy step, we need (i / j) steps in total.

Time: O(n), 
Space: O(n).
'''

class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1 :
            return 0
        for i in range(n - 1 , 0, -1) :
            if n % i == 0 :
                return self.minSteps(i) + (n // i)
