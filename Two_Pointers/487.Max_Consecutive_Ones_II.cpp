/*
Create a window [start,i] which contains one or no zero.
Loop on the nums, return the maximum window size along this way.

Time: O(n);
Space: O(1).
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0,start=0,zero=0,k=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            while(zero>k){
                if(nums[start]==0) zero--;
                start++;
            }
            res=max(res,i-start+1);
        }
        return res;
    }
};

/*
Follow up:
What if the input numbers come in one by one as an infinite stream? 
In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. 
Could you solve it efficiently?

We cannot access past num, so we store all zeros in a queue.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //follow up
        int res=0,start=0,zero=0;
        queue<int> q;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) q.push(i);
            if(q.size()>1){
                start=q.front()+1;q.pop();
            }
            res=max(res,i-start+1);
        }
        return res;
    }
};