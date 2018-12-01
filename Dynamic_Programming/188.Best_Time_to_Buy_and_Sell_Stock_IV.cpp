/*
General version of Stock III.
Implement DP as stock III:
dp[k][i] means most profit at i th day at most k transactions.
the  state transition formular is:
dp[k][i]=max{dp[k][i-1],max(prices[i]-prices[j]+dp[k-1][j-1])}, j=[1,2,3...i].
It can be modified to:
dp[k][i]=max{dp[k][i-1],prices[i]-min(prices[j]-dp[k-1][j-1])}, j=[1,2,3...i].
we should also handle the situation where j=0:
we can buy and sell any times within one day, so when j=0, 
the min(prices[j]-dp[k-1][j-1]) becomes prices[0]. means we buy and sell k-1 times at the first day, and then buy prices[0].
That why we start cur_min with prices[0] for every k.
when we loop on prices by i, we can get the min(prices[j]-dp[k-1][j-1]) at the same time.
because j's range here is [1,2,3...i] exactly.

but several other issues need to be consider:
time limited, memory limited...
When k>=n/2, we don't have to bother, just return maxN function.
After all, the worst case is [1,5, 2,6, 3,5], ascending order only within pairs and pairs,
In this case ,we should transact n/2 times.

Time:O(k*n);
Space O(k*n).
*/

class Solution {
public:
    int maxN(vector<int>& prices){
        int res=0;
        for(int i=1;i<prices.size();i++){
            res+=max(0,prices[i]-prices[i-1]);
        }
        return res;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        if(k>=n/2) return maxN(prices);
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        for(int t=1;t<=k;t++){
            int cur_min=prices[0];
            for(int i=1;i<n;i++){
                cur_min=min(cur_min,prices[i]-dp[t-1][i-1]);
                dp[t][i]=max(dp[t][i-1],prices[i]-cur_min);
            }
        }
        return dp[k][n-1];
    }
};

