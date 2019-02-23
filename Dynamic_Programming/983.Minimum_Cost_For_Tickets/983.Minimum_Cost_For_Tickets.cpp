class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int, int> day_to_index;
        int n = days.size();
        for (int i = 0; i < n; i++) {
            day_to_index[days[i]] = i;
        }
        
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            int cost1, cost7, cost30;
            int one_ago = days[i] - 1;
            if (one_ago < days[0]) cost1 = costs[0];
            else {
                auto it = --day_to_index.upper_bound(one_ago);
                int pre = it -> second;
                cost1 = dp[pre] + costs[0];
            }
            int seven_ago = days[i] - 7;
            if (seven_ago < days[0]) cost7 = costs[1];
            else {
                auto it = --day_to_index.upper_bound(seven_ago);
                int pre = it -> second;
                cost7 = dp[pre] + costs[1];
            }
            int thirty_ago = days[i] - 30;
            if (thirty_ago < days[0]) cost30 = costs[2];
            else {
                auto it = --day_to_index.upper_bound(thirty_ago);
                int pre = it -> second;
                cost30 = dp[pre] + costs[2];
            }
            
            dp[i] = min(cost1, min(cost7, cost30));
        }
        return dp[n-1];
    }
};