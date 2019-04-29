class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> record;
        int res = 0;
        
        for (int i = 1; i < A.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((long)A[i] - A[j] > INT_MAX || (long)A[i] - A[j] <= INT_MIN) continue;
                int dif = A[i] - A[j];
                record[i][dif]++;
                if (record[j].count(dif))
                {
                    record[i][dif] += record[j][dif];
                    res += record[j][dif];
                }
            }
        }
        return res;
    }
};