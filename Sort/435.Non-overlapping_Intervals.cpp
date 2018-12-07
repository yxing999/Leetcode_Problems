/*
This is a template solution for find the maximum intervals who are non-onerlapping.
First, we sort the intervals by the end ascendingly.
Then we loop on the sorted intervals, all the Interval whoes start is smaller than current end can be removed.
which on we should keep? the one with smallest end, because it is safest, for the further Intervals to be non-onerlapping.
That is why we sort the intervals by the end ascendingly at the start.

Time: O(n);
Space: O(1).
*/

class Solution {
public:
    static bool compare(Interval a,Interval b){
        return a.end<b.end;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int cur_end=INT_MIN;
        int count=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i].start>=cur_end){
                cur_end=intervals[i].end;
                count++;
            }
        }
        return intervals.size()-count;
    }
};