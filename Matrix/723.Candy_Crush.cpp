/*
A problem about matrix processing.
In every step, loop on the matrix and for every candy:
Find if it should be removed, remove them,
then drop the rest.
Repeat until no candy should be removed.

Time :O((m*n)^2),
Space:O(m*n).
*/

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<pair<int,int>> rm;
        while(true){
            rm.clear();
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==0) continue;
                    int x1=i,x2=i,y1=j,y2=j;
                    while(x1>=0&&board[x1][j]==board[i][j]) x1--;
                    while(x2<m&&board[x2][j]==board[i][j]) x2++;
                    while(y1>=0&&board[i][y1]==board[i][j]) y1--;
                    while(y2<n&&board[i][y2]==board[i][j]) y2++;
                    if(x2-x1>3||y2-y1>3) rm.push_back({i,j});
                }
            }
            if(rm.empty()) break;
            for(auto ele:rm) board[ele.first][ele.second]=0;
            //drop
            for(int j=0;j<n;j++){
                int temp=m-1;
                for(int i=m-1;i>=0;i--){
                    if(board[i][j]) swap(board[i][j],board[temp--][j]);
                }
            }
        }
        return board;
    }
    
};