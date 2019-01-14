/*
A medium problem, a fundamental exercise for Union Find.
Scan on half of the matrix, connect friend, count the circle.

Time: O(n^2),
Space: O(n).
*/

class Solution {
public:
    int count;
    vector<int> root;
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        count=n;
        root.resize(n);
        for(int i=0;i<n;i++) root[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(M[i][j]) connect(i,j);
            }
        }
        return count;
    }
    int find(int i){
        if(root[i]!=i) root[i]=find(root[i]);
        return root[i];
    }
    void connect(int i,int j){
        int rooti=find(i);
        int rootj=find(j);
        if(rooti!=rootj) {
            root[rooti]=root[rootj];
            count--;
        }
    }
};