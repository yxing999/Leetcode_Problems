/*
Typical Greedy algorithm.

Three integers: 
jump: current number of jumps,
cur_end: current maximum index within jump,
reach: maximum index of next jump.

When we get cur_end, we need next jump, so jump plus one, cur_end pudates to reach.
When cur_end overpass last index, break the loop, return jump.

Time: O(n);
Space: O(1).
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,cur_end=0,reach=0;
        for(int i=0;i<nums.size();i++){
            if(cur_end>=nums.size()-1) break;
            reach=max(reach,i+nums[i]);
            if(i==cur_end){
                jump++;
                cur_end=reach;
            }
        }
        return jump;
    }
};