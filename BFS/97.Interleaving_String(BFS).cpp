/*
Implement a pair<i,j>, i is length of matched s1, j is length of matched s2.
In every layer, we try to move to {i+1,j} or {i,j+1}.
if we got i+j equals to n3, which means s1,s2 are all matched, return true, else return false.
Remember to memorize the {i,j} who cannot move to {n1,n2}.

Time: O(n1*n2);
Space:O(n1*n2). 
*/

namespace std{
    template<> struct hash<pair<int,int>>{
        size_t operator()(const pair<int,int> &p)const{
            return hash<int>()(p.first)^hash<int>()(p.second);
        }
    };
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3) return false;
        unordered_set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto temp=q.front();q.pop();
                int i1=temp.first,i2=temp.second;
                int i3=i1+i2;
                if(i3==n3) return true;
                if(i1<n1&&s1[i1]==s3[i3]){
                    if(!visited.count({i1+1,i2})){
                        visited.insert({i1+1,i2});
                        q.push({i1+1,i2});
                    }
                }
                if(i2<n2&&s2[i2]==s3[i3]){
                    if(!visited.count({i1,i2+1})){
                        visited.insert({i1,i2+1});
                        q.push({i1,i2+1});
                    }
                }
            }
        }
        return false;
    }
};