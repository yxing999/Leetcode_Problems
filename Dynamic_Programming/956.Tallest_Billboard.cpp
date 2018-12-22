/*
Pretty tricky DP problem.
We build a hashmap to represent dp array, to query previous results more efficiently.
dp[d]=k, d is the difference of two rod, k is the tallest shorter rod among all pairs with d difference.
loop on rods, add rod to previous pairs and upadte the dp.

There are 3 ways to add:
1.|x|d|rod|
  |x|
2.|x|d   |
  |x|rod|  (rod<d)
3.|x|d|
  |x|rod|  (rod>d)

Time: O(n*m), n is length of rods, m is all possible sums of rod.
Space: O(m)
*/

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int,int> dp;
        dp[0]=0;
        for(int rod:rods){
            unordered_map<int,int> temp(dp);
            for(auto it:temp){
                int d=it.first;
                dp[d+rod]=max(dp[d+rod],temp[d]);
                if(d>=rod) dp[d-rod]=max(dp[d-rod],temp[d]+rod);
                else dp[rod-d]=max(dp[rod-d],temp[d]+d);
            }
        }
        return dp[0];
    }
};