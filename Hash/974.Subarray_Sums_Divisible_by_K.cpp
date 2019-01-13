/*
Create a hash table to store the sum from 0 to current i,
You should only store the result after mod.
if index a and b has the same sum result(after mod),
the subarray between a and b is divisible by K.

Time: O(n),
Space: O(n+k).
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n=A.size();
        vector<int> sum(n+1);
        for(int i=1;i<=n;i++) sum[i]=((sum[i-1]+A[i-1])%K+K)%K;
        vector<int> cnt(K);
        cnt[0]=1;
        int res=0;
        for(int i=1;i<=n;i++){
            res+=cnt[sum[i]];
            cnt[sum[i]]++;
        }
        return res;
    }
};