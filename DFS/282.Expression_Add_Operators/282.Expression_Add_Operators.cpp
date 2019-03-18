class Solution {
public:
    vector<string> addOperators(string num, int target) {
        DFS(num, target, "", 0, 0, 0);
        
        return res;
    }
    
    void DFS(string &num, int &target, string cur_str, long pre_num, long cur_val, int pos) {
        if (pos == num.size()) {
            if (cur_val == target) {
                res.push_back(cur_str);
            }
            return;
        }
        
        for (int i = pos + 1; i <= num.size(); i++) {
            if (num[pos] == '0' && i > pos + 1) return;
            
            string add_str = num.substr(pos, i - pos);
            long add_int = stol(add_str);

            if (pos == 0) {
                DFS(num, target, add_str, add_int, add_int, i);
            }
            else {
                DFS(num, target, cur_str + "+" + add_str, add_int, cur_val + add_int, i);
                DFS(num, target, cur_str + "-" + add_str, -add_int, cur_val - add_int, i);
                DFS(num, target, cur_str + "*" + add_str, pre_num * add_int, cur_val - pre_num + pre_num * add_int, i);
                }
        }
    }
private:
    vector<string> res;
};