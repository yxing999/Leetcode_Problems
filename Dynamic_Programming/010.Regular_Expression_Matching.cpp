/*
A hard DP problem based on string.
Usually, to work out two-string matching problems, we build a 2D array, DP[m+1][n+1].
dp[i][j] represents s.substr(0,i) and p.substr(0,j).

For this question, initial condition is dp[0][0]=0, empty string matches empty string.
for dp[i][j], we need to handle according to p[j-1]:
1.p[j-1]=='*'. 
	What can this '*' do?
	(1).It can remove itself together with preceding character.(dp[i][j-2])
	(2).It can duplicate preceding character one ore more times.(i>0&&dp[i-1][j]&&match(s[i-1],p[j-2]))
2.p[j-1]!='*'.
	Just get dp[i][j] from dp[i-1][j-1].(dp[i][j]=i>0&&dp[i-1][j-1]&&match(s[i-1],p[j-1]))

Time: O(m*n),
Space O(m*n).
m,n is length of s and p.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){//p[0] won't be '*', so we don't need judgement (j>1).
                    dp[i][j]=dp[i][j-2]||i>0&&dp[i-1][j]&&match(s[i-1],p[j-2]);
                }
                else{
                    dp[i][j]=i>0&&dp[i-1][j-1]&&match(s[i-1],p[j-1]);
                }
            }
        }
        return dp[m][n];
    }

    bool match(char a, char b){
        if(b=='.') return true;
        else return a==b;
    }
};