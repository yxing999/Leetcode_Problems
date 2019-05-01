class Solution {
public:
    struct compare
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.first > b.first;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        vector<int> res(2, 0);
        int k = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        int cur_max = INT_MIN;
        
        vector<int> point(k, 0);
        for (int i = 0; i < k; i++)
        {
            cur_max = max(cur_max, nums[i][0]);
            pq.push({nums[i][0], i});
        }
        res[0] = pq.top().first;
        res[1] = cur_max;
        
        while(true)
        {
            auto temp = pq.top();
            pq.pop();
            int i = temp.second;
            if (point[i] == nums[i].size() - 1) return res;
            point[i]++;
            pq.push({nums[i][point[i]], i});
            cur_max = max(cur_max, nums[i][point[i]]);
            if (res[1] - res[0] > cur_max - pq.top().first)
            {
                res[0] = pq.top().first;
                res[1] = cur_max;
            }
        }
        
        return res;
    }
};