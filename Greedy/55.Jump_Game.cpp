/*
Weird problem.
The only obstacle preventing us from reaching end is 0.
if we can skip 0, return true; if we can't, return false.
In what situation we can't? [4,3,2,1,0,4].

Time: O(n), two for loop, but still O(n).
Space: O(1).
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<2) return true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0){
                int k=i;
                for(;k>=0;k--)
                    if(nums[k]>i-k) break;
                if(k<0) return false;
            }
        }
        return true;
    }
};

/*
Look at this problem from higher perspective.
It is problem about greedy.

Time: O(n);
Space: o(1).
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_reach=0;
        for(int i=0;i<n;i++){
            if(max_reach<i) return false;
            max_reach=max(max_reach,i+nums[i]);
        }
        return max_reach>=n-1;
    }
};