/*
Equal binary values must contain equal numbers of 1's.
So, firstly, we evenly split the 1's into three parts, 
there are some 0's between these parts, that's where we can set i and j.
[xxxx|yyyy|zzzz]
The value of third part [zzzz] is fixed, so we can set i and j based on it,
making [xxxx] and [yyyy] has the same 0's as [zzzz] on the tail.

Set three pointers, compare these three number.

Time:O(n),
Space:O(n).
*/

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        unordered_map<int,vector<int>> ones;
        int cnt=0;
        for(int i=0;i<A.size();i++){
            if(A[i]) cnt++;
            ones[cnt].push_back(i);
        }
        if(cnt==0) return {0,2};
        if(cnt%3!=0) return {-1,-1};
        
        int tailzeros=ones[cnt].size();
        if(ones[cnt/3].size()<tailzeros||ones[cnt*2/3].size()<tailzeros)
            return {-1,-1};
        int i=ones[cnt/3][tailzeros-1],j=ones[cnt*2/3][tailzeros-1];
        int temp=cnt/3;
        for(int a=i,b=j,c=A.size()-1;temp>0;a--,b--,c--){
            if(A[a]!=A[b]||A[a]!=A[c]) return {-1,-1};
            if(A[a]==1) temp--;
        }
        return {i,j+1};
    }
};