class Solution {
    unordered_map<int, bool> Memo;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) 
            return true;
        if (2 * desiredTotal > maxChoosableInteger * (1 + maxChoosableInteger)) 
            return false;
        return DFS_with_Memo(maxChoosableInteger, desiredTotal, 0);
    }
    
    bool DFS_with_Memo(int &max, int desired, int status) {
        if (desired <= 0) return false;
        
        if (Memo.count(status)) return Memo[status];
        
        for (int i = 1; i <= max; i++) {
            if ((status >> i) & 1 == 1) continue;
            if (DFS_with_Memo(max, desired - i, status | 1 << i) == false){
                Memo[status] = true;
                return true;
            }
        }
        Memo[status] = false;
        return false;
    }
};