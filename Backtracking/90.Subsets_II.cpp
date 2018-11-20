/*
Find all possible subsets, the solution must not contain duplicate subsets.
This is a following problem of 78.Subsets, still a typical backtracking solution.
Just one more operation to handle the duplicates.

My understanding of backtracking:
Imagine a tree structure, every recursion is a move to child node, every i in a for loop
is a new root. So the method to handle the duplicate is:
Ignore the root whose value is the same as the last one.
(not the child whose value is the same as his parent) 
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