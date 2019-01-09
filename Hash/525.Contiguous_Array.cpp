/*
The input array contains only 0 and 1.
we Create a hash map to memorize the sum from index 0 to i.
Here is a trick, we take 0 as -1 when we do the sum,
so when the number of 0 and 1 is equal, the sum is 0.

We loop on the nums, built the hash mp, if we find the same sum before current index,
that means range mp[sum] to i contains same number of 0 and 1.

mp alway memorizes the earliest index of sum.

Time: O(n),
Space: O(n).
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res=0,sum=0;
        unordered_map<int,int> mp={{0,-1}};
        for(int i=0;i<nums.size();i++){
            sum+= nums[i]==1? 1:-1;
            if(mp.count(sum)) res=max(res,i-mp[sum]);
            else mp[sum]=i;
        }
        return res;
    }
};