/*
A straight forward solution:
Make use of a max_heap, which stores the numbers in the window,
Be careful about the edge case: k=0.

Time: O(n*logk).
Space: O(k).
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int,greater<int>> num_in_window;
        vector<int> res;
        if(k==0) return res;
        for(int i=0;i<k;i++) num_in_window[nums[i]]++;
        res.push_back(num_in_window.begin()->first);
        for(int i=k;i<nums.size();i++){
            num_in_window[nums[i]]++;
            if(--num_in_window[nums[i-k]]==0) num_in_window.erase(nums[i-k]);
            res.push_back(num_in_window.begin()->first);
        }
        return res;
    }
};


/*
Follow up: Could you solve it in linear time?
Yes, I can, but only after referring to Dalao's solution.

We build a priority_queue by ourselves, which stores the index of numbers within the window,
keep the biggest at front, pop this only when it equals to i-k, which means it is out of window.
when pushing new index i, pop_back all indices that nums[back]<nums[i], because they are useless when we have nums[i].
It is a monotonic queue.

Time: O(n).
Space:O(k).
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> index_in_window;
        for(int i=0;i<nums.size();i++){
            if(!index_in_window.empty()&&index_in_window.front()==i-k)
                index_in_window.pop_front();
            while(!index_in_window.empty()&&nums[index_in_window.back()]<nums[i])
                index_in_window.pop_back();
            index_in_window.push_back(i);
            if(i>=k-1) res.push_back(nums[index_in_window.front()]);
        }     
        return res;
    }
};
