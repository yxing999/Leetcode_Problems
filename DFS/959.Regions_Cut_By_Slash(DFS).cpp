/*
Split every region into 4 parts:
 __
|\/|
|/\|
 --
Make the corresponding relationship between parts and numbers:
top:0,right:1,bottom:2,left:3.
So, there are n*n*4 parts in the grid.

Create a array visited, with size n * n * 4, to revord the parts we visited.

Loop on grid(every parts), if the current part is not visited, res plus one,
then set all parts that connected to this part to 1.

*Code is ugly. -_-

Time: O(n^2),
Space: O(n^2).
*/

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> visited(n * n * 4, 0);
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k =0; k < 4; k++) {
                    if (!visited[(i * n + j) * 4 + k]) {
                        res++;
                        DFS(grid, visited, i, j, k);
                    }
                }
            }
        }
        
        return res;
    }
    
    void DFS(vector<string> &grid, vector<int> &visited, int i, int j, int k) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || visited[(i * n + j) * 4 + k])
            return;
        
        visited[(i * n + j) * 4 + k] = 1;
        
        switch (k) {
            case 0:
                if (grid[i][j] =='/') {
                    DFS(grid, visited, i, j, 3);
                }
                else if (grid[i][j] =='\\') {
                    DFS(grid, visited, i, j, 1);
                }
                else {
                    DFS(grid, visited, i, j, 1);
                    DFS(grid, visited, i, j, 2);
                    DFS(grid, visited, i, j, 3);
                }
                DFS(grid, visited, i - 1, j, 2);
                break;
            case 1:
                if (grid[i][j] =='/') {
                    DFS(grid, visited, i, j, 2);
                }
                else if (grid[i][j] =='\\') {
                    DFS(grid, visited, i, j, 0);
                }
                else {
                    DFS(grid, visited, i, j, 0);
                    DFS(grid, visited, i, j, 2);
                    DFS(grid, visited, i, j, 3);
                }
                DFS(grid, visited, i, j + 1, 3);
                break;
            case 2:
                if (grid[i][j] =='/') {
                    DFS(grid, visited, i, j, 1);
                }
                else if (grid[i][j] =='\\') {
                    DFS(grid, visited, i, j, 3);
                }
                else {
                    DFS(grid, visited, i, j, 0);
                    DFS(grid, visited, i, j, 1);
                    DFS(grid, visited, i, j, 3);
                }
                DFS(grid, visited, i + 1, j, 0);
                break;
            case 3:
                if (grid[i][j] =='/') {
                    DFS(grid, visited, i, j, 0);
                }
                else if (grid[i][j] =='\\') {
                    DFS(grid, visited, i, j, 2);
                }
                else {
                    DFS(grid, visited, i, j, 0);
                    DFS(grid, visited, i, j, 1);
                    DFS(grid, visited, i, j, 2);
                }
                DFS(grid, visited, i, j - 1, 1);
                break;
        }
    }
};