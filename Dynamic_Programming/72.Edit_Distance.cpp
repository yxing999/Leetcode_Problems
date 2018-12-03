/*
A good question about DP.
Follow the consistent strategy for string, We built a 2D array dp.
dp[i][j] mean the minimum steps from word1 left i part to word2 left j part.
i and j are all length.
facing word1[i-1] and word2[j-1],
if they are equal, dp[i][j]=dp[i-1][j-1], we don't need to handle these two same characters.
if they are different, dp[i][j] can come from three directions:
dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1,
they all have corresponding operation:
dp[i-1][j-1]:replace,just replace word1[i-1] with word2[j].
dp[i-1][j]:delete,delete word1[i-1].
dp[i][j-1]:insert, insert word2[j-1].

Time: O(n1*n2).
Space: O(n1*n2).
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        for(int i=0;i<=n1;i++) dp[i][0]=i;
        for(int i=0;i<=n2;i++) dp[0][i]=i;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        return dp[n1][n2];
    }
};
