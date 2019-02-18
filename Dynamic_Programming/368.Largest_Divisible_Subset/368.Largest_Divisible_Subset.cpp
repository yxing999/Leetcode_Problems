/*
Sort the input nums, because if a can be divided by b, a can be divided by b's divisors.
Create a dp array, each element is a pair, containing last index of divisor and length of divisible subset until now.
At index i, scan all previous elements of dp:
Find the divisible numbers and choose the largest one, update dp, record the largest subset until now in maxlen.
maxlen records the index.
After that, insert the largest subset into res.

Time:O(n^2),
Space:O(n).
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> dp(n,{-1,1});//<last,num>
        int maxlen=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i].second<dp[j].second+1){
                        dp[i]={j,dp[j].second+1};
                        if(dp[i].second>dp[maxlen].second)
                            maxlen=i;
                    }
                }
            }
        }
        vector<int> res;
        while(dp[maxlen].first!=-1){
            res.insert(res.begin(),nums[maxlen]);
            maxlen=dp[maxlen].first;
        }
        res.insert(res.begin(),nums[maxlen]);
        return res;
    }
};