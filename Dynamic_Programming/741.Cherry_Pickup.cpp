/*
Pretty diffcult problem.
The Problem ask you to go from grid[0][0] to grid[n-1][n-1],
and then back to grid[0][0] from grid[n-1][n-1].

You can't do 2 dp travels, (0,0)->(n-1,n-1),then (n-1.n-1)->(0,0).
Because you can only guarantee max within one travel, 
but not the whole process,

The strategy is:
imagine two people, go from grid[n-1][n-1], to grid[0][0], 
every one move 1 grid at one step.
Create 3D dp array, (x1,y1,x2),
This two guys move at the same steps, so x1+y1=x2+y2, y2=x1+y1-x2.
dp[x1][y1][x2] means, most cherries these two guys can get,
one from (x1,y1), the other from (x2,y2).
if these two guys at the same grid, only one can get this cherry,
it doesn't matter who get this.

Time: O(n^3),
Space: O(n^3).
*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-2)));
        return max(0,recursion(n-1,n-1,n-1,dp,grid));
    }
    int recursion(int x1,int y1,int x2,vector<vector<vector<int>>> &dp, vector<vector<int>>& grid){
        int y2=x1+y1-x2;
        if(x1<0||y1<0||x2<0||y2<0) return -1;
        if(grid[x1][y1]==-1||grid[x2][y2]==-1) return -1;
        if(x1==0&&y1==0) return grid[x1][y1];
        if(dp[x1][y1][x2]!=-2) return dp[x1][y1][x2];
        int temp=max(max(recursion(x1-1,y1,x2-1,dp,grid),recursion(x1,y1-1,x2-1,dp,grid)),max(recursion(x1-1,y1,x2,dp,grid),recursion(x1,y1-1,x2,dp,grid)));
        if(temp<0){
            dp[x1][y1][x2]=-1;
            return -1;
        }
        else{
            temp+=grid[x1][y1];
            if(x1!=x2) temp+=grid[x2][y2];
        }
        dp[x1][y1][x2]=temp;
        return temp;
    }
};