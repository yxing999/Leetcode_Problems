class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        string str = slim(s);
        int n = str.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return print(memo, str, 0, n - 1);
    }
    
    int print(vector<vector<int>> &memo, string &str, int start, int end)
    {
        if (start > end) return 0;
        if (memo[start][end]) return memo[start][end];
        
        int temp = print(memo, str, start, end - 1) + 1;
        
        for (int i = end - 1; i >= start; i--)
        {
            if (str[i] == str[end])
            {
                temp = min(temp, print(memo, str, start, i) + print(memo, str, i + 1, end - 1));
            }
        }
        memo[start][end] = temp;
        return memo[start][end];
    }
    
    string slim(string s)
    {
        string res;
        res += s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1]) res += s[i];
        }
        return res;
    }
};