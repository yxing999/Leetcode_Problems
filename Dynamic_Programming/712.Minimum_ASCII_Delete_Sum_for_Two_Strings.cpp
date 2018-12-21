/*
Problem about two string trasfer, go with DP.
At dp[i][j], if s1[i-1]==s2[j-1], dp[i][j]=dp[i-1][j-1];
if s1[i-1]!=s2[j-1], dp[i][j] can come from dp[i-1][j] by deleting s1[i-1],
or dp[i][j-1] by deleting s2[j-1].

Time: O(n1*n2),
Space: O(n1*n2).
*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        for(int i=1;i<=n1;i++) dp[i][0]=dp[i-1][0]+s1[i-1];
        for(int j=1;j<=n2;j++) dp[0][j]=dp[0][j-1]+s2[j-1];
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[n1][n2];
    }
};