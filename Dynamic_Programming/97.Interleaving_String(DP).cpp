/*
DP to solve the string problem.
Follow the template:
Create a 2D array based on length of s1 and s2.
dp[i][j] means left i characters of s1 and left j characters of s2 can construct left i+j characters of s3.
dp[i][j] comes from two directions: dp[i-1][j], dp[i][j-1].
dp[i][j]=(dp[i-1][j]&&s1[i-1]==s3[i+j-1])||(dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
To implement this, we should initate dp[i][0] and dp[0][j]. 

Time :O(n1*n2);
Space: O(n1+n2).
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3) return false;
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1));
        dp[0][0]=true;
        for(int i=1;i<=n1;i++) dp[i][0]=dp[i-1][0]&&(s1[i-1]==s3[i-1]);
        for(int i=1;i<=n2;i++) dp[0][i]=dp[0][i-1]&&(s2[i-1]==s3[i-1]);
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                dp[i][j]=(dp[i-1][j]&&s1[i-1]==s3[i+j-1])||(dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[n1][n2];
    }
};