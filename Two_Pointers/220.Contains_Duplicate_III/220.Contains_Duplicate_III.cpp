/*
Maintain a multiset containing k - 1 integers, start and i mark the edge of included integers.
for current i, find the two adjacent numbers of nums[i], 
if the absolute difference is no bigger than t, just return true.

During the process we build the multiset, when the number of integers is less than k - 1,
follow the same strategy when we try to insert a new integer.

Time: O(n*log(k)),
Space: O(k).
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) return false;
        if (nums.empty()) return false;
        multiset<int> mset;
        mset.insert(nums[0]);
        int start = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            auto it1 = mset.upper_bound(nums[i]);
            if (it1 != mset.end())
            {
                if ((long)*it1 - nums[i] <= t) return true;
            }
            if (it1 != mset.begin())
            {
                auto it2 = --it1;
                if ((long)nums[i] - *it2 <= t) return true;
            }
            mset.insert(nums[i]);
            if (i - start >= k) 
            {
                auto r = mset.find(nums[start]);
                mset.erase(r);
                start++;
            }
        }
        return false;
    }
};