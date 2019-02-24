namespace std{
    template<> struct hash<vector<int>>{
        size_t operator()(const vector<int> &l) const{
            return hash<int>()(l[0]) ^ hash<int>()(l[1]);
        }
    };
}
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> row, col, diag, rdiag;
        unordered_set<vector<int>> lamp(lamps.begin(), lamps.end());
        for (auto l: lamps) {
            int x = l[0], y = l[1];
            row[x]++;
            col[y]++;
            diag[y-x]++;
            rdiag[x+y]++;
        }
        vector<int> res;
        for (auto query: queries) {
            int x = query[0], y = query[1];
            if (row[x] || col[y] || diag[y-x] || rdiag[y+x] ) res.push_back(1);
            else res.push_back(0);
            
            for (int i = x - 1 ;i <= x + 1 ;i++) {
                for (int j = y - 1 ;j <= y + 1 ;j++) {
                    if (lamp.count({i, j})){
                        lamp.erase({i, j});
                        row[i]--;
                        col[j]--;
                        diag[j-i]--;
                        rdiag[j+i]--;
                    }
                }
            }
        }
        return res;
    }
};