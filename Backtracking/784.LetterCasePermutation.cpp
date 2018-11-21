/*
Backtracking, every step, move forward from S[i] and change_cased S[i], two status.
iterative solution also works, but nothing valuable to explore.

Time O(2^k),k is the number of alpha of S.
Space: O(1).
*/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        int n=S.size();
        backtracking(S,res,0,n);
        return res;
    }
    void backtracking(string &S,vector<string> &res,int i,int end){
        if(i>=end){
            res.push_back(S);
            return;
        }
        if(!isalpha(S[i])) backtracking(S,res,i+1,end);
        else{
            backtracking(S,res,i+1,end);
            if(isupper(S[i])) S[i]=tolower(S[i]);
            else S[i]=toupper(S[i]);
            backtracking(S,res,i+1,end);
        }
    }
};