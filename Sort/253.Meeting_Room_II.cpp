/*
Find the maximum number of room of the meeting timeline.
Make use of the map, which will sort automatically by key.
The key of map is start and end time of intervals, value of start is 1, value of end is -1,
representing open and close a room.
the map builds a timeline for us, loop on the map, find the max number of room along this line.

Time: O(n*longn);
Space: O(n).
*/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> time;
        for(auto i:intervals){
            time[i.start]++;
            time[i.end]--;
        }
        int room=0;
        int res=0;
        for(auto ele:time){
            room+=ele.second;
            res=max(room,res);
        }
        return res;
    }
};

/*
Another solution makes use of a Priority_queue.
Build a min-heap to store the end time of every Interval,
Regard the top one is the current time, if the upcoming Interval's start smaller that current time，
the current meeting has to continue, push the upcoming Interval into the heap.
Only the upcoming Interval's start is bigger or equal to the current time,
the current meeting can end, current time move to the next Interval's end.

During this process, every Interval was pushed, only the current meeting can end, we pop it.
So the size of priority_queue is the maximum number of room during the process.

Time: O(n*longn);
Space: O(n).
*/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        auto compare=[](Interval a, Interval b){return a.start<b.start;};
        priority_queue<int,vector<int>,greater<int>> nowtime;
        sort(intervals.begin(),intervals.end(),compare);
        for(int i=0;i<intervals.size();i++){
            if(!nowtime.empty()&&nowtime.top()<=intervals[i].start) nowtime.pop();
            nowtime.push(intervals[i].end);
        }
        return nowtime.size();
    }
};