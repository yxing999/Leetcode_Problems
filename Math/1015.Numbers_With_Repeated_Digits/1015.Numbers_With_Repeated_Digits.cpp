class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> digits = toArray(N + 1);
        
        int res = 0;
        int n = digits.size();
        unordered_set<int> used;
        
        res += (digits[0] - 1) * (permutation(9, n - 1));
        used.insert(digits[0]);
        for (int i = 1; i < n; i++) {
            for (int k = 0; k < digits[i]; k++) {
                if (!used.count(k)) {
                    res += permutation(9 - i, n - i - 1);
                }
            }
            if (used.count(digits[i])) break;
            used.insert(digits[i]);
        }
        
        for (int i = 1; i < n; i++) {
            res += 9 * permutation(9, i - 1);
        }
        return N - res;
    }
    
    vector<int> toArray(int n) {
        vector<int> res;
        while (n > 0) {
            res.insert(res.begin(), n % 10);
            n /= 10;
        }
        return res;
    }
    
    int permutation(int n, int m) { // choose m out of n
        if (m == 0) return 1;
        
        return permutation(n - 1, m - 1) * n;
    }
};