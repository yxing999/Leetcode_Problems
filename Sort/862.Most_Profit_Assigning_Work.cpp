/*
The problem is to find most profit among the array of job with different difficulties.
The strategy is: Sort and Find.
Two things should be mentioned:
1.It is not guaranteed that higher difficulty with higher profit.
2.There may be duplicates in the difficulty array.

Time: O(nlogn+mlogm),
Space: O(n).
*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> mp;
        for(int i=0;i<profit.size();i++) mp.push_back({difficulty[i],profit[i]});
        sort(mp.begin(),mp.end());sort(worker.begin(),worker.end());
        int res=0,cur=0,curmax=0;
        for(int i:worker){
            while(i>=mp[cur].first&&cur<profit.size()) curmax=max(curmax,mp[cur++].second);
            res+=curmax;
        }
        return res;
    }
};