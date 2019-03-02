class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string unit = "";
        for (int i = 0; i< n; i++) unit += '.';
        vector<string> temp(n, unit);
        
        backtracking(res, temp, 0, n);
        return res;
    }
    
    void backtracking(vector<vector<string>> &res, vector<string> &temp, int r, int n) {
        if (r == n) {
            res.push_back(temp);
            return;
        }
        for (int y = 0; y < n; y++) {
            if (check(r, y)) {
                temp[r][y] = 'Q';
                put(r, y);
                backtracking(res, temp, r + 1, n);
                temp[r][y] = '.';
                remove(r, y);
            }
        }
    }
    
    bool check(int x, int y) {
        return !(col[y] || diag[x - y] || rdiag[x + y]);
    }
    
    void put(int x, int y) {
        col[y]++;
        diag[x - y]++;
        rdiag[x + y]++;
    }
    
    void remove(int x, int y) {
        col[y]--;
        diag[x - y]--;
        rdiag[x + y]--;
    }
private:
    unordered_map<int, int> col, diag, rdiag; 
};