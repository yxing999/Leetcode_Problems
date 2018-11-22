/*
Return all possible sentences.
Notice "all possible", we should think of backtracking,
but this is a hard problem, we need to build a DP array before backtracking.

1.dp[i] represents whether s.substr(0,i) can be broken according to the wordDict.
  for string problem, we usually use length of substring as dp's index, to handle empty string.
2.Next step is backtracking, we still use length as input, not the s's index.
  From end of s to the start of s.
Time：DP:O(n^2),backtracking:O(2^n)
      Total:O(2^n).
Space: O(n).
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--)
                if(dp[j]&&dict.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;//this "break" reduces runtime significantly. 
                }
        }
        vector<string> res;
        vector<string> temp;
        backtracking(s,dict,res,temp,dp,n);
        return res;
    }
    void backtracking(string &s,unordered_set<string> &dict,vector<string> &res,vector<string> &temp, vector<bool> &dp,int cur){
        if(cur<=0){
            string now;
            for(string s:temp)
                now=s+" "+now;
            now.resize(now.size()-1);
            res.push_back(now);
            return;
        }
        else{
            for(int i=cur;i>=0;i--){
                if(dp[i]&&dict.count(s.substr(i,cur-i))){
                    temp.push_back(s.substr(i,cur-i));
                    backtracking(s,dict,res,temp,dp,i);
                    temp.pop_back();
                }
            }
        }
    }
};