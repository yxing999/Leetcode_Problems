/*
A trick for this problem is back tracing: 
From Pacific and Atlantic, we trace the cells with heigher or equal height respectively.
the cells we can reach are the cells from where water can flow to Pacific or Atlantic. 

We create two 2-D array with the same size of input matrix, 
to record the cells we visited respectively.

We only need to reach each cell once from each Ocean.

Time:O(m * n), 
Space: O(m * n).
*/

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        vector<vector<int>> p_visited(m, vector<int>(n, 0));
        vector<vector<int>> a_visited(m, vector<int>(n, 0));
        vector<pair<int, int>> res;
        
        for (int i = 0; i < m; i++) {
            DFS(matrix, p_visited, i, 0, m, n); 
            DFS(matrix, a_visited, i, n - 1, m ,n); 
        }
        
        for (int j = 0; j < n; j++) {
            DFS(matrix, p_visited, 0, j, m, n); 
            DFS(matrix, a_visited, m - 1, j, m, n); 
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p_visited[i][j] && a_visited[i][j]) 
                    res.push_back({i, j}); 
            }
        }
        
        return res;
    }
    
    void DFS(vector<vector<int>> &matrix, vector<vector<int>> &visited, int i, int j, int m, int n) {
        if (visited[i][j]) return;
        
        visited[i][j] = 1;
        
        if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j]) 
            DFS(matrix, visited, i - 1, j, m, n); 
        if (i + 1 < m && matrix[i + 1][j] >= matrix[i][j]) 
            DFS(matrix, visited, i + 1, j, m, n);
        if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j]) 
            DFS(matrix, visited, i, j - 1, m, n); 
        if (j + 1 < n && matrix[i][j + 1] >= matrix[i][j]) 
            DFS(matrix, visited, i, j + 1, m, n);
    }
};