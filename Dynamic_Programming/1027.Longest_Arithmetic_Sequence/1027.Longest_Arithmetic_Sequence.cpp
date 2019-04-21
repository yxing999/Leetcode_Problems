/*
Up to index i, there may be several longest subsequence with equal length and different steps.
We need record them all.
So we create a hash map, key is index, value is dif with length up to current index.
Loop on every pair of A, update the dp map, record the max length.

Time : O(n^2),
Space: O(n^2).
Average far less than this.
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp; //index, dif, length
        int res = 0;
        
        for (int i = 1; i < A.size(); i++)
        {
            for (int j = 0; j < i; j++) 
            {
                int dif = A[i] - A[j];
                dp[i][dif] = max(dp[i][dif], dp[j][dif] + 1);
                res = max(res, dp[i][dif]);
            }
        }
        return res + 1;
    }
};