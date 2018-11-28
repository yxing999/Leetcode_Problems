/*
Remove minimum parentheses to valid string, the core strategy is DFS.

Before core process, another task is counting how many left and right parentheses to be removed.
Up to i index, if the right parentheses ')' is more than left, it should be removed, and won't be count.
Number of left parentheses to be removed is the number of it more than the right int the end.

DFS:kind of brute force, remove every possible '(' and ')', then test the validity of new string.
Make sure to skip duplicates.

Time: O(2^n);
Space: O(n).
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int l=0,r=0;
        for(int i=0;i<s.size();i++){
            l+=(s[i]=='(');
            if(l==0) r+=(s[i]==')');
            else l-=(s[i]==')');
        }
        DFS(s,res,l,r,0);
        return res;
    }
    bool isvalid(string s){
        int cur=0;
        for(int i=0;i<s.size();i++){
            cur+=(s[i]=='(');
            cur-=(s[i]==')');
            if(cur<0) return false;
        }
        return cur==0;
    }
    void DFS(string s,vector<string> &res,int l,int r,int start){
        if(l==0&&r==0){
            if(isvalid(s)){
                res.push_back(s);
                return;
            }
        }
        if(l<0||r<0) return;
        for(int i=start;i<s.size();i++){
            if(i!=start&&s[i]==s[i-1]) continue;
            string cur=s;
            if(s[i]=='('){
                cur.erase(i,1);
                DFS(cur,res,l-1,r,i);
            }
            if(s[i]==')'){
                cur.erase(i,1);
                DFS(cur,res,l,r-1,i);
            }
        }
    }
};