/*
Build a hashmap to store the sum from 0 to i.
On i, hash[cur_sum-k] is number of subarray end at i.
initially, hash[0]=1, this helps to record subarray start from index 0.

Time: O(n);
Space: O(n).
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int cur_sum=0;
        unordered_map<int,int> hash;
        hash[0]++;
        for(int i=0;i<nums.size();i++){
            cur_sum+=nums[i];
            res+=hash[cur_sum-k];
            hash[cur_sum]++;
        }
        return res;
    }
};