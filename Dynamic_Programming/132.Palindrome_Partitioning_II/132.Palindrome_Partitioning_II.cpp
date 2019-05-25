class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        vector<int> dp(n + 1);
        dp[0] = -1;
        
        for (int i = 0; i < n; i++) {
            dp[i + 1] = i;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j]) {
                    if ((j + 1 < i - 1 && palindrome[j + 1][i - 1]) || j + 1 >= i - 1){
                        palindrome[j][i] = true;
                        dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n];
    }
};