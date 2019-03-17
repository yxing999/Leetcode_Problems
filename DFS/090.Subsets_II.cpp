/*
Find all possible subsets, the solution must not contain duplicate subsets.
This is a following problem of 78.Subsets, still a typical backtracking solution.
Just one more operation to handle the duplicates.

My understanding of backtracking:
Imagine a tree structure, every recursion is a move to child node, every i in a for loop
is a new root. So the method to handle the duplicate is:
Ignore the root whose value is the same as the last one.
(not the child whose value is the same as his parent) 

Time complexity analysis:
The time complexity is mainly determined by the for loops:
n times T(n):
for(int i=0;i<=n;i++)
    Backtracking(nums,res,temp,0,n,i);

T(n):
for(int i=start;i<end;i++){
    if(i!=start&&nums[i]==nums[i-1]) continue;
    temp.push_back(nums[i]);
    Backtracking(nums,res,temp,i+1,end,k);
    temp.pop_back();
}
There are two factors we should pay attention to:
1.In T(n), for every i, T(n-i-1) will be called, i is from 0 to n-1,
  so we get the recursively relationship:
    T(n)=T(n-1)+T(n-2)+T(n-3)+...+T(0)
    ***
    Here, some one may ask, the temp also changed except the start, 
    it will also affect recursion time, how can you continue to use T(n-1),
    there are two parameters changed.
    I have the same question, and my answer is: I DON'T KNOW, neither do the blog guys.
    We are all CS guys, not math guys, what a pity.
    ***

    write this relationship until all right elements are T(0):
    T(n)=2^(n-1)T(0)=2^(n-1);
2.In the core function, we call Backtracking n+1 times with parameter k from 0 to n,
  So the total F(n)=(n+1)*2^(n-1)=O(n*2^(n))

Space:O(n).
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=0;i<=n;i++)
            Backtracking(nums,res,temp,0,n,i);
        return res;
    }
    void Backtracking(vector<int> &nums,vector<vector<int>> &res, vector<int> &temp,int start,int end, int k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<end;i++){
            if(i!=start&&nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            Backtracking(nums,res,temp,i+1,end,k);
            temp.pop_back();
        }
    }
};

/*
Iterative solution:
Sort the numsfirst,then scan the nums, for the nums[i],
if nums[i] is not the same as the last one, copy the current res, and append nums[i] to each of them,
then append new subset to the back of res.
if nums[i] is the same as nums[i-1], only append nums[i] to the subsets that we added in the last step,
which is in nums[i-1], to avoid the duplicates.

Time complexity analysis is interesting,
if we only care about the for loop, it is O(2^n), it is not the real time apparently.
shoud we consider the details within the for loop? I don't know.
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res={{}};
        sort(nums.begin(),nums.end());
        int cur_size=1,start=0;
        for(int i=0;i<nums.size();i++){
            start=i>0&&nums[i]==nums[i-1]? cur_size:0;
            cur_size=res.size();
            for(int j=start;j<cur_size;j++){
                vector<int> temp=res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};



