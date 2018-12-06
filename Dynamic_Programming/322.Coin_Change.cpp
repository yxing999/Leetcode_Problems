/*
A ordinary DP problem,
take the money amount as dp array's index, dp[0]=0, others are amount+1 at start.
for every dp[i], loop on coins set, if coins[j] can be inserted,
choose the smaller one of dp[i], dp[i-coins[j]]+1.

Time: O(amount*n);
Space: O(amount).
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i>=coins[j]) dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount]==amount+1? -1:dp[amount];
    }
};