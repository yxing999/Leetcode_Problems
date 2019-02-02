'''
Not the best but easy solution.
Solve this problem recursively:
When n is even, return f(n/2)+1;
when n is odd, choose the smaller one between f(n+1) and f(n-1), plus one.

Time: O(2^(n/2))
Space: O(1).
'''

class Solution:
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==1:
            return 0
        elif n%2==0:
            return self.integerReplacement(n/2)+1
        else:
            return min(self.integerReplacement(n+1),self.integerReplacement(n-1))+1