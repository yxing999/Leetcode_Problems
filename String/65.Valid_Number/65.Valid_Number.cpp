class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0) return false;
        string new_s = removespace(s);
        removeuary(new_s);
        if (new_s.size() == 0) return false;
        
        vector<string> parts(2);
        if (new_s.find('e') != string::npos) {
            int f = new_s.find_first_of('e');
            int e = new_s.find_last_of('e');
            if (f != e) return false;
            parts[0] = new_s.substr(0, f);
            parts[1] = new_s.substr(f + 1, new_s.size() - 1 - f);
            removeuary(parts[1]);
            if (parts[0].size() == 0 || parts[1].size() == 0) return false;
        }
        else {
            parts[0] = new_s;
        }
        
        for (int k = 0; k < 2; k++) {
            int dot = 0;
            for (int i = 0; i < parts[k].size(); i++) {
                if (isdigit(parts[k][i])) continue;
                else if (parts[k][i] == '.') {
                    if (k == 0) {
                        if (dot == 1 || parts[k].size() == 1) return false;
                        else {
                            dot = 1;
                            if (i == 0 || i == parts[k].size() - 1) continue;
                            if (!isdigit(parts[k][i - 1]) || !isdigit(parts[k][i + 1])) return false;
                        }
                    }
                    else return false;
                }
                else return false;
            }
        }
        return true;
    }
    
    string removespace(string s) {
        int i = 0, j = s.size() - 1;
        while (s[i] == ' ' && i < j) i++;
        while (s[j] == ' ' && i <= j) j--;
        return s.substr(i, j - i + 1);
    }
    
    void removeuary(string &s) {
        if (s.size() == 0) return;
        if (s[0] == '+' || s[0] == '-') {
            s.erase(0, 1);
        }
    }
};