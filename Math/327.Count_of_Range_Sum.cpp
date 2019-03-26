/*
Let's translate requirement of problem into inequality.
For the (i,j] satisfying requirement:

lower<=sum[j]-sum[i]<=upper,  sum[i] is sum of first i-th elements.

We can rewrite that into:

sum[j]-upper<=sum[i]<=sum[j]-lower.

We loop on the nums array from left to right, 
When we are at j, we already have every sum[i] before j, 
We search among these sum[i],count the number of them that satisfy the inequality above.

We create a multiset to count the number in O(logn),
Don't forget to insert a 0 into multiset initially, the sum of first j elements can be a result, too.

Time:O(nlogn),
Space:O(n).
*/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res=0;
        long long sum=0;
        multiset<long long> sums;
        sums.insert(0);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            res+=distance(sums.lower_bound(sum-upper),sums.upper_bound(sum-lower));
            sums.insert(sum);
        }
        return res;
    }
};