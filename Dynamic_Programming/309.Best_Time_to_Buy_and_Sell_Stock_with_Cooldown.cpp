/*
Implement three DP array:
hold: hold[i] means hold stock at ith day, so we can sell on the next day.
idle: idle[i] means doing nothing at ith day, so we can buy on the next day.
sell: sell[i] means sell at ith day, we must hold on (i-1)th day.

Time: O(n);
Space:O(n).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<int> hold(n),idle(n),sell(n);
        hold[0]=-prices[0];
        for(int i=1;i<n;i++){
            hold[i]=max(hold[i-1],idle[i-1]-prices[i]);
            idle[i]=max(sell[i-1],idle[i-1]);
            sell[i]=hold[i-1]+prices[i];
        }
        return max(sell[n-1],idle[n-1]);
    }
};
