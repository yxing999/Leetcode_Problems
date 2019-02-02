'''
The time complexity can be reduced significantly with some mathematics analysis.
Set a variable step to memorize the number of steps.
When n is even, divede n by 2;
When n is odd, we always want n become a multiple of 4,
so that we can divide n by 2 in two consecutive times.
if n mod 4 equals 1, n--; if n mod 4 equals 3, n++.
an edge case is n==3, n should minus 1.

Time: O(log(n)),
Space:O(1).
'''

class Solution:
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        res=0
        while n>1:
            if n%2==0:
                n/=2
            else:
                if n%4==1 or n==3:
                    n-=1
                else:
                    n+=1
            res+=1
        return res


'''
Optimized version with better average time complexity.
'''

class Solution:
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        res=0
        while n>1:
            if n%2==0:
                res+=1
                n/=2
            elif n%4==1:
                res+=3
                n//=4
            elif n==3:
                res+=2
                n=1
            else:
                res+=3
                n=n//4+1
        return res