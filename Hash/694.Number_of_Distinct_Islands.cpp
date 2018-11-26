/*
Number of islands problem.
But the DFS,Union Find,BFS or some other methods to count islands are trivial for this problem.
We only need to think about how to identify distinct islands.
My strategy is to implement a hash set, to store some identity of islands.
The identity is a string, which stores every point‘s position to the left-top point.
Every island goes through the same DFS function, so islands of the same shape have the same identity string.

Time: Every point is visited once, so the time complexity is O(m*n).
Space: O(m*n).
*/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> island;
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    string str="";
                    DFS(grid,i,j,str,i,j);
                    if(!island.count(str)) res++;
                    island.insert(str);
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<int>>& grid,int i,int j,string &str,int &x,int &y){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0) return;
        grid[i][j]=0;
        str+=to_string(i-x)+to_string(j-y);
        DFS(grid,i-1,j,str,x,y);
        DFS(grid,i+1,j,str,x,y);
        DFS(grid,i,j-1,str,x,y);
        DFS(grid,i,j+1,str,x,y);
    }
};