/*
Every result is a arithmetic sequence, whose difference is 1.
For every result, the intitial number x and the length n is correponding,
in other words, if this result exists, when n is determined, x is also determined.

For the sequence with initial number x and length n,
the sum is x*n+n*(n-1)/2, if this is a result, x*n+n*(n-1)/2=N,
We rewirte it as x*n=N-n*(n-1)/2,

We can get the strategy from the above content,
Loop n from 1, get the temp integer N-n(n-1)/2 on every step, representing x*n.
if temp<=0, that means n is too large, we end this loop.
else, if temp mod n equals 0, which means integer x exists, we plus one to res.

Time: O(logn),
Space: O(1).
*/

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res=0;
        for(int n=1;;n++){
            int temp=N-n*(n-1)/2;
            if(temp<=0) break;
            if(temp%n==0) res++;
        }
        return res;
    }
};