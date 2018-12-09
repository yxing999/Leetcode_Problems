/*
"Sorted","O(longn) time" indicate us to implement binary search.
For the judgement on which side of the target:
We compare nums[mid] and nums[mid+1]( mid+1 won't overflow,because right is always bigger than left),
result depends on the parity of mid.
Let's review some examples first:
[1,1,2,2,(3),3,4,5,5] mid=4,target on the right, nums[mid]=nums[mid+1];
[1,2,2,3,(3),4,4,5,5] mid=4,target on the left, nums[mid]!=nums[mid+1];
[1,1,2,(2),3,3,4], mid=3,target on the right,nums[mid]!=nums[mid+1];
[1,2,2,(3),3,4,4,], mid=3,target on the left,nums[mid]=nums[mid+1];

Imagine the array does not contain this single number,
if mid is even, nums[mid] should equal to nums[mid+1],
if mid is odd, nums[mid] should not equal to nums[mid+1];
then, if the target is on the right, it doesn't affact above rule,
else, if the target is on the left, it reverses the above rule.

For the movement of left and right, right moves to mid, left moves to mid+1,
corresponding to judgement left<right, it won't cause infinite loop.

In the end, test [1,1,2] and [1,2,2], I found nums[left] is the target.

Time: O(logn),
Space: O(1).
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]) left=mid+1;
                else right=mid;
            }
            else{
                if(nums[mid]==nums[mid+1]) right=mid;
                else left=mid+1;
            }
        }
        return nums[left];
    }
};

/*
Some tricky methods.
i and i^1 can make connection between 0-1, 2-3, 4-5.....

Time: O(logn),
Space: O(1).
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]==nums[mid^1]) left=mid+1;
            else right=mid;
        }
        return nums[left];
    }
};
