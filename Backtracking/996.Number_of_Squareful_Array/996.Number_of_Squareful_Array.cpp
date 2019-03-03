class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        int res = 0;
        vector<int> temp;
        vector<int> visited(n,0);
        
        dfs(A, temp, res, visited, n);
        return res;
    }
    
    void dfs(vector<int> &A, vector<int> &temp,int &res, vector<int> &visited, int n) {
        if (temp.size() == n) {
            res++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            if (i != 0 && A[i] == A[i - 1] && !visited[i - 1]) continue;
            
            if (temp.empty()) {
                temp.push_back(A[i]);
                visited[i] = 1;
                dfs(A, temp, res, visited, n);
                visited[i] = 0;
                temp.pop_back();
            }
            else {
                if (issquare(A[i] + temp.back())) {
                    temp.push_back(A[i]);
                    visited[i] = 1;
                    dfs(A, temp, res, visited, n);
                    visited[i] = 0;
                    temp.pop_back();
                }
            }
        }
    }
    
    bool issquare(int x) {
        return sqrt(x) == (int) sqrt(x);
    }
};