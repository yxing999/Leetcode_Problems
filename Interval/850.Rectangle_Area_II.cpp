/*
Kind of follow up problem after 218.The Skyline Problem.
We still solve it by line sweep, it is a 2-D version.
Imagin an infinite line vertical to x-axis, scan from left to right,
when encounter the x contains points:
1.Calculate width of several intervals.
2.Add area between this x and last x.(width*(curx-lastx))
3.Handle points at this x: add new intervals to curpoint and remove end intervals.

Time: O(n^2*log(n)),
Space: O(n);
*/

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int mod=1e9+7;
        for(auto rec:rectangles){
            data[rec[0]].insert({rec[1],rec[3],1});
            data[rec[2]].insert({rec[1],rec[3],0});
        }
        long long res=0;
        int lastx=data.begin()->first;
        for(auto ele:data){
            int curx=ele.first;
            res+=(long long)(curx-lastx)*getwidth();
            res%=mod;
            lastx=curx;
            for(auto p:ele.second){
                if(p[2]) curpoint[p[0]].insert(p[1]);
                else{
                    auto temp=curpoint[p[0]].find(p[1]);
                    curpoint[p[0]].erase(temp);
                    if(curpoint[p[0]].empty()) curpoint.erase(p[0]);
                }
            }
        }
        return res;
    }
    
    map<int,multiset<vector<int>>> data;
    map<int,multiset<int>> curpoint;
    long long getwidth(){
        if(curpoint.empty()) return 0;
        else{
            long long res=0;
            int maxy=-1;
            for(auto e:curpoint){
                if(e.first>=maxy) {
                    res+=*e.second.rbegin()-e.first;
                    maxy=*e.second.rbegin();
                }
                else{
                    if(*e.second.rbegin()>maxy){
                        res+=*e.second.rbegin()-maxy;
                        maxy=*e.second.rbegin();
                    }
                }
            }
            return res;
        }
    }
};