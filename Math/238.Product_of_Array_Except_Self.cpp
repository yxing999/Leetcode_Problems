/*
Loop on nums from left, at index i, get the product of array before i,
Then loop on nums from right, set a int right to record the product on the right of i.
Multipy the res[i] and right at index i, get the ultimate result.

Time: O(n),
Space: O(a).
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0]=1;
        for(int i=1;i<nums.size();i++){
            res[i]=res[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i]*=right;
            right*=nums[i];
        }
        return res;
    }
};