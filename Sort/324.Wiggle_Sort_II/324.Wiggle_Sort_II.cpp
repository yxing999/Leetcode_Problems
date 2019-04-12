/*
It is not easy to handle equal values.
We should try to construct new array pair by pair, with bigger pair at the front.
For example: [0, 1, 2, | 3, 4, 5] -> [2, 5, 1, 4, 0, 3]
if the length is odd, we should put the smallest one at end position.
[0, | 1, 2, 3, | 4, 5, 6] -> [3, 6, 2, 5, 1, 4, 0].

Time: O(n * logn),
Space: O(n).
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int p = (n - 1) / 2, q = n - 1;
        vector<int> res;
        for (int i = 0; i < n / 2; i++)
        {
            res.push_back(nums[p--]);
            res.push_back(nums[q--]);
        }
        if (p >= 0) res.push_back(nums[p]);
        nums = res;
    }
};
