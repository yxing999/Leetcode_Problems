/*
Very easy problem,
Just mind the corner case and end time.

Time:O(n),
Space:O(1).
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        int left=0,right=0;
        while(right<nums.size()-1){
            if(nums[right]==nums[right+1]-1) right++;
            else{
                if(left==right) res.push_back(to_string(nums[left]));
                else res.push_back(to_string(nums[left])+"->"+to_string(nums[right]));
                left=++right;
            }
        }
        if(left==right) res.push_back(to_string(nums[left]));
        else res.push_back(to_string(nums[left])+"->"+to_string(nums[right]));
        return res;
    }
};