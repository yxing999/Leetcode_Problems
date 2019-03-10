/*
Very typical backtracking problem.
Just need a hash set to avoid duplicates by recording used num on the same layer.

Time: O(2^n),
Space: O(n).
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        
        unordered_set<int> visited;
        for(int i = 0; i < n; i++) {
            if (!visited.count(nums[i])) {
                visited.insert(nums[i]);
                temp.push_back(nums[i]);
                backtracking(nums, res, temp, i + 1, n);
                temp.pop_back();
            }
        }
            
        return res;
    }
    
    void backtracking(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, int k, int n) {
        if (k >= n) return;
        
        unordered_set<int> visited;
        
        for (int i = k; i < n; i++) {
            if (nums[i] >= temp.back() && !visited.count(nums[i])) {
                visited.insert(nums[i]);
                temp.push_back(nums[i]);
                res.push_back(temp);
                backtracking(nums, res, temp, i + 1, n);
                temp.pop_back();
            }
        }
    }
};