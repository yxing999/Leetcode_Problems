/*
The approach to this problem is reverse the operation.
Because later stamps don't care about the former stamp.
Imagine we got the target, we want to unstamp it to "???????".

Time: O(m*(n-m)), m is length of stamp, n is length of target,
Space: O(n).
*/

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        string temp=target;
        string end(target.size(),'?');
        while(temp!=end){
            int cur=unstamp(temp,stamp);
            if(cur==target.size()) return {};
            res.insert(res.begin(),cur);
        }
        return res;
    }
    int unstamp(string &target,string stamp){
        for(int i=0;i<target.size();i++){
            int s=0,t=i;
            int flag=0;
            while(s<stamp.size()&&t<target.size()&&(target[t]=='?'||target[t]==stamp[s])){
                if(target[t]==stamp[s]) flag=1;
                s++;
                t++;
            }
            if(s==stamp.size()&&flag){
                for(int k=0;k<stamp.size();k++){
                    target[i+k]='?';
                }
                return i;
            }
        }
        return target.size();
    }
};