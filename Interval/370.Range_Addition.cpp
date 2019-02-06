/*
If you loop on updates, update every range, it could be accepted, but waste a lot of time.
The efficient strategy is:
For every range, we only add inc at startindex, minus inc at endindex+1,
This two number will memorize the whole range,
Then we loop on result array, use a integer sum to represent current value by adding res[i] at every i.

Time: O(length+n), n is the length of updates
Space: O(1).
*/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length,0);
        for(auto v:updates){
            res[v[0]]+=v[2];
            if(v[1]+1<length) res[v[1]+1]-=v[2];
        }
        int sum=0;
        for(int i=0;i<length;i++){
            sum+=res[i];
            res[i]=sum;
        }
        return res;
    }
};