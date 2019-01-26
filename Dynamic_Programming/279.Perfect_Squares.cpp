/*
For every perfect square, the result is 1,
For normal number, we can try every perfect number k which is less than n,
try result of n-k plus 1, which means (n-k)+k=n,
Then choose the smallest one.

Time: O(n*logn),
Space:O(n).
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        for(int i=1;i*i<=n;i++){
            dp[i*i]=1;
        }
        for(int i=2;i<=n;i++){
            if(dp[i]==INT_MAX){
                for(int j=1;j*j<i;j++){
                    dp[i]=min(dp[i],dp[i-j*j]);
                }
                dp[i]++;
            }
        }
        return dp[n];
    }
};

/*
If you have a strong math background, you can solve this problem by Lagrange's four-square theorem.
https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem

But it is out of most ordinary programmer.
I prefer not to implement here.
*/