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
        unordered_map<char,int> ch_hand;
        for(char ch:hand) ch_hand[ch]++;
        int res=backtracking(board,ch_hand);
        return res==INT_MAX?-1:res;
    }
    void clean(string &board){
        for(int i=0,j=0;i<=board.size();i++){
            if(i<board.size()&&board[i]==board[j]) continue;
            if(i-j>=3){
                board=board.substr(0,j)+board.substr(i);
                i=j;
            }
            else j=i;
        }
    }
    int backtracking(string board,unordered_map<char,int> &ch_hand){
        clean(board);
        if(board.empty()) return 0;
        int res=INT_MAX;
        for(int i=0,j=0;i<=board.size();i++){
            if(i<board.size()&&board[i]==board[j]) continue;
            int need=3-(i-j);
            if(ch_hand[board[j]]>=need){
                ch_hand[board[j]]-=need;
                int temp=backtracking(board.substr(0,j)+board.substr(i),ch_hand);
                if(temp<INT_MAX) res=min(res,need+temp);
                ch_hand[board[j]]+=need;
            }
            j=i;
        }
        return res;
    }
};