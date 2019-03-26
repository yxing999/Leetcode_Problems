/*
One of the most interesting Leetcode problems.
DFS? DP? Bu Cun Zai De.
It is like a Nao Jin Ji Zhuan Wan.

For an input array [x,x,x,x,x,x], the max result is x / x * x * x * x * x.
Realize by bracketing last (n - 1) elements.

Time: O(n),
Space: O(1).
*/

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);
        else if (nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);
        
        else {
            string res;
            for (int i = 0; i < nums.size(); i++) {
                if (i == 0) res += to_string(nums[i]) + '/' + '(';
                else if (i == nums.size() - 1) res += to_string(nums[i]) + ')';
                else res +=to_string(nums[i]) + '/';
            }
            return res;
        }
    }
};