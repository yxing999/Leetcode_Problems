/*
Great problem based on a famous game.
This is a problem about Recursion, or DFS, but I still classify it into Backtracking.
Try to add new ball at every gap of board(same color, make the three-consecutive).
Clean the board to remove consecutive balls when moving to a new branch.

Time: O(n*2^n);
Space: O(m).  n is board's size, m is hand's size.

*/

class Solution {
public:
    int findMinStep(string board, string hand) {
        for (char ch: hand) ch_hand[ch]++;
        int res = INT_MAX;
        
        DFS(board, res, 0);
        
        return res == INT_MAX? -1: res;
    }
    
    string clean(string board) {
        int n = board.size();
        for (int i = 0; i < n - 2; i++) {
            if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
                int j = i + 3;
                while (j < n && board[i] == board[j]) j++;
                return clean(board.substr(0, i) + board.substr(j, n - j));
            }
        }
        return board;
    }
    
    void DFS(string board, int &res, int balls) {
        string new_board = clean(board);
        if (new_board.size() == 0) res = min(res, balls);
        
        int j = 0;
        for (int i = 0; i < new_board.size(); i = j) {
            while(j < new_board.size() && new_board[j] == new_board[i]) j++;
            int need = 3 - (j - i);
            
            if (ch_hand[new_board[i]] >= need) {
                ch_hand[new_board[i]] -= need;
                new_board.insert(i, need, new_board[i]);
                DFS(new_board, res, balls + need);
                new_board.erase(i, need);
                ch_hand[new_board[i]] += need;
            }
        }
    }
private:
    unordered_map<char, int> ch_hand;
};