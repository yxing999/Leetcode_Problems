/*
O(m+n) space solution:
Create two sets to store the row and column of zero.

Time: O(mn),
Space: O(m+n).
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row,col;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i:row){
            for(int j=0;j<n;j++) matrix[i][j]=0;
        }
        for(int j:col){
            for(int i=0;i<m;i++) matrix[i][j]=0;
        }
    }
};

/*
Constant space solution:
find the first zero matrix[x][y], use the row[x] and column[y] to store other zero information.

Time: O(mn),
Space: O(1).
*/

class Solution {
public:
    void findzero(vector<vector<int>>& matrix, int &x,int &y,int m,int n){
        for(x=0;x<m;x++){
            for(y=0;y<n;y++){
                if(matrix[x][y]==0) return;
            }
        }
        x=-1;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int x,y;
        int m=matrix.size();
        int n=matrix[0].size();
        findzero(matrix,x,y,m,n);
        if(x==-1) return;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][y]=0;
                    matrix[x][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(i==x) continue;
            if(matrix[i][y]==0)
                for(int j=0;j<n;j++) matrix[i][j]=0;
        }
        for(int j=0;j<n;j++){
            if(j==y) continue;
            if(matrix[x][j]==0)
                for(int i=0;i<m;i++) matrix[i][j]=0;
        }
        for(int i=0;i<m;i++) matrix[i][y]=0;
        for(int j=0;j<n;j++) matrix[x][j]=0;
    }
};