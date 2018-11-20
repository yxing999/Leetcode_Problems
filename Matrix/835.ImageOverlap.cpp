/*
Find the largest possible overlap of 1 between two matrix.
The first solution I got is 
brute force:
For every possible overlap position, I scan every element of overlapped part,
count the result and get the max.

temp1 counts the situation that B is on the left-top of A,
temp2 counts the situation that B is on the right-bottom of A.
(or A is on the left-top of B, so the same index as temp1, just exchanges B and A)
temp3 counts the situation that B is on the right-top of A.
temp4 counts the situation that B is on the left-bottom of A.
(or A is on the right-top of B, so the same index as temp1, just exchanges B and A)

when B is on the left-top of A, the A[k][m] overlaps with B[n-i+k-1][n-j+m-1],
i, j is the right-bottom most point's position in A.
when B is on the right-top of A, the A[p][q] overlaps with B[n-1-i+p][q-j];
i, j is the left-bottom most point's position in A.

It is easy to test the correctness of the relationship by set i=0,j=0,k=0,m=0, 
see if A[0][0] corresponds to B[n-1][n-1].

Time: O(n^4),
Space: O(1);
*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B){
        int res=0;
        int temp1,temp2,temp3,temp4;
        int n=A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp1=0;
                temp2=0;
                temp3=0;
                temp4=0;
                for(int k=0;k<=i;k++){
                    for(int m=0;m<=j;m++){
                        if(A[k][m]==1&&B[n-i+k-1][n-j+m-1]==1) temp1++;
                        if(B[k][m]==1&&A[n-i+k-1][n-j+m-1]==1) temp2++;
                    }
                }
                res=max(res,temp1);
                res=max(res,temp2);
                for(int p=0;p<=i;p++){
                    for(int q=j;q<n;q++){
                        if(A[p][q]==1&&B[n-1-i+p][q-j]==1) temp3++;
                        if(B[p][q]==1&&A[n-1-i+p][q-j]==1) temp4++;
                    }
                }
                res=max(res,temp3);
                res=max(res,temp4);
            }
        }
        return res;
    }
};

/* 
Brute force can be accepted, but it is ugly.
I found that for each overlapping position, the pair<△i,△j> is unique,
where △i,△j are differences of i and j of A,B.
Based on this discovery，another efficient solution is:
1.Scan A and B, remember all 1's coordinates into va,vb respectively.
2.Loop on all combinations (a,b) of va and vb, increase count[t*△i+△j] by 1.(here I set t=100)
3.Loop on count and find the maximal result.

Explanation about t*△i+△j :
For easier implementation of unordered_map(due to my bad grasp of C++), I set the type of key
as int. So, I need to find some strategy to convert the unique pair<△i,△j> to a unique int,
which is  t*△i+△j.
To make t*△i+△j is also unique, I need to think about the size of t:
the range of △i is (-n,n), when multiplied by t, it becomes (-n*t,n*t).
the range of △j is (-n,n), to make new int unique, the difference of adjacet elements of t*△i should be bigger than range(-n,n).
So, t>2*n-1.
Time: O(n^2+ab), a,b are number of 1 in A,B.
Space: O(n^2)
*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int t=100;
        int n=A.size();
        vector<pair<int,int>> va;
        vector<pair<int,int>> vb;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]) va.push_back({i,j});
                if(B[i][j]) vb.push_back({i,j});
            }
        }
        unordered_map<int,int> count;
        for(auto a:va){
            for(auto b:vb){
                int di=a.first-b.first;
                int dj=a.second-b.second;
                count[t*di+dj]++;
            }
        }
        int res=0;
        for(auto ele:count)
            res=max(res,ele.second);
        return res;
    }
};

/*
The STL map of C++ supports pair<int,int> as its key,
So the solution can be:
*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        vector<pair<int,int>> va;
        vector<pair<int,int>> vb;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]) va.push_back({i,j});
                if(B[i][j]) vb.push_back({i,j});
            }
        }
        map<pair<int,int>,int> count;
        for(auto a:va){
            for(auto b:vb){
                int di=a.first-b.first;
                int dj=a.second-b.second;
                count[{di,dj}]++;
            }
        }
        int res=0;
        for(auto ele:count)
            res=max(res,ele.second);
        return res;
    }
};