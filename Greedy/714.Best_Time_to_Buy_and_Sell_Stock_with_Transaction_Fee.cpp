/*
It is a DP problem, but the most important idea is greedy,
Which is in every single day i, we keep the hold and sell amount maximum.
So after loop on n days, the sell on n-th day is maximum.

Time: O(n);
Space: o(n).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> hold(n);
        vector<int> sell(n);
        hold[0]=-prices[0];
        for(int i=1;i<n;i++){
            hold[i]=max(hold[i-1],sell[i-1]-prices[i]);
            sell[i]=max(sell[i-1],hold[i-1]+prices[i]-fee);
        }
        return sell[n-1];
    }
};