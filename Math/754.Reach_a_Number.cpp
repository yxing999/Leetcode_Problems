/*
I don't think this is a easy problem. It is pretty tricky.
The strategy is:
Get the absolute value of target.(positive or negative don't affect result)
Find the step n, where sum just overpasses or equals to target.(sum of n-1 steps is less than target).

1.If sum equals to target, return n;

2.If the difference of sum and target is even, 
  which means we can let k-th step from right to left,
  making sum become sum-2k, euqla to target. So we also return n.

3.If the difference of sum and target if odd, we need more steps to make this difference become even.
  If n is odd, n+1 is even, even+odd is still odd, n+2 is odd, odd+odd is even.
  so, we return n+2;
  If n is even, n+1 is odd, odd+odd is even, so we return n+1.

Time: O(1),
Space: O(1).

*/

class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int n=ceil((-1.0+sqrt(1.0+8.0*target))/2);
        int sum=(n+1)*n/2;
        if(sum==target) return n;
        else if((sum-target)%2==0) return n;
        else if((sum-target)%2!=0){
            if(n%2==0) return n+1;
            else return n+2;
        }
    }
};