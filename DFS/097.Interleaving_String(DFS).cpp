/*
To implement DFS for this problem, we need some memory strategy, or we will get TLE.
For every (i,j) that cannot make i3 up to s3.size(), we memorize it, 
next we meet this (i,j), just return false.
Once the i3 reach s3.size(), res=true.

Time: O(n1*n2),
Space :O(n1*n2).
*** I am not sure about this, my mathematical ablility can't analyze this so far.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3) return false;
        bool res=false;
        unordered_set<int> st;
        DFS(s1,s2,s3,0,0,0,res,st);
        return res;
    }
    void DFS(string &s1,string &s2,string &s3,int i1,int i2,int i3,bool &res,unordered_set<int> &st){
        int key=i1*s3.size()+i2;
        if(st.count(key)) return;
        if(i3==s3.size()){
            res=true;
            return;
        }
        if(i1<s1.size()&&s1[i1]==s3[i3]){
            DFS(s1,s2,s3,i1+1,i2,i3+1,res,st);
        }
        if(i2<s2.size()&&s2[i2]==s3[i3]){
            DFS(s1,s2,s3,i1,i2+1,i3+1,res,st);
        }
        st.insert(key);
    }
};


/*
The above solution used a tricky method to represent unique (i,j) by a key, 
which I analyzed in Matrix/835.ImageOverlap.cpp
we can also just use pair(i,j) to represent that.

Time: O(2^n3),
Space O(n1*n2).
*/

namespace std{
    template<> struct hash<pair<int,int>>{
        size_t operator()(const pair<int,int> &l) const{
            return hash<int>()(l.first)^hash<int>()(l.second);
        }
    };
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3) return false;
        bool res=false;
        unordered_set<pair<int,int>> st;
        DFS(s1,s2,s3,0,0,0,res,st);
        return res;
    }
    void DFS(string &s1,string &s2,string &s3,int i1,int i2,int i3,bool &res,unordered_set<pair<int,int>> &st){
        if(st.count({i1,i2})) return;
        if(i3==s3.size()){
            res=true;
            return;
        }
        if(i1<s1.size()&&s1[i1]==s3[i3]){
            DFS(s1,s2,s3,i1+1,i2,i3+1,res,st);
        }
        if(i2<s2.size()&&s2[i2]==s3[i3]){
            DFS(s1,s2,s3,i1,i2+1,i3+1,res,st);
        }
        st.insert({i1,i2});
    }
};