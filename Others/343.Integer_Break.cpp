/*
A math problem.
It is not diffcult to realize:
Except 2 and 3, we should extract all 3 from n until the tail is equal or less than 4, 
and then multiply the tail.
Time:O(n),
Space:O(a).
*/

class Solution {
public:
    int integerBreak(int n) {
        if(n==2||n==3) return n-1;
        int res=1;
        while(n>4){
            res*=3;
            n-=3;
        }
        return res*n;
    }
};

/*
We can also calculate the number of 3 and the tail.
The time can be O(1).
*/