/*
Find 3 numbers whose sum equals 0.
We should sort thte sum at start, for implementation of two pointers,
also for removing duplicates.

Loop on nums, for i index, loop on the numbers on the right of i,
if current sum bigger than 0, right move to the left,
if current sum less than 0, left move to the right.

Time: O(n^2);
Space: O(1).
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i!=0&&nums[i]==nums[i-1]) continue;
            int left=i+1,right=n-1;
            while(left<right){
                int temp=nums[i]+nums[left]+nums[right];
                if(temp==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while(nums[left]==nums[left-1]&&left<right) left++;
                    right--;
                    while(nums[right]==nums[right+1]&&left<right) right--;
                }
                else if(temp>0) right--;
                else left++;
            }
        }
        return res;
    }
};

/*
Just a practice for user-defined hash function.
*/

namespace std{
    template<> struct hash<vector<int>>{
        size_t operator()(const vector<int> &l) const{
            return hash<int>()(l[0])^hash<int>()(l[1])^hash<int>()(l[2]);
        }
    };
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int left=i+1,right=n-1;
            while(left<right){
                int temp=nums[i]+nums[left]+nums[right];
                if(temp==0){
                    res.insert({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(temp>0) right--;
                else left++;
            }
        }
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;
    }
};