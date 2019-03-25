class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subAtMostK(A, K) - subAtMostK(A, K - 1);
    }
    
    int subAtMostK(vector<int> &A, int K) {
        unordered_map<int, int> hash;
        int res = 0;
        int left = 0;
        
        for (int right = 0; right < A.size(); right++) {
            hash[A[right]]++;
            while (hash.size() > K) {
                hash[A[left]]--;
                if (hash[A[left]] == 0) hash.erase(A[left]);
                left++;
            }
            res += right - left + 1;
        }
        
        return res;
    }
};