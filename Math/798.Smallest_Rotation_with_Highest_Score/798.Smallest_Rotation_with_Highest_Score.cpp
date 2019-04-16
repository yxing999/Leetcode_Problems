class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size();
        vector<int> score(n * 2 + 1, 0); // to reduce judgement in the code
        for (int i = 0; i < n; i++)
        {
            if (i - A[i] >= 0)
            {
                score[0]++;
                score[i - A[i] + 1]--;
            }
            score[i + 1]++;
            score[i + n - A[i] + 1]--;
        }
        
        int maxscore = 0, res = 0;
        int curscore = 0;
        for (int i = 0; i < n; i++)
        {
            curscore += score[i];
            if (curscore > maxscore)
            {
                maxscore = curscore;
                res = i;
            }
        }
        return res;
    }
};