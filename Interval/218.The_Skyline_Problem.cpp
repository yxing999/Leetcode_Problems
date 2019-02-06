/*
To draw the outline of the city, we need to find the highest building on every x.
First, we sort the start and end x-coordinate overall，
At the start position, we store h, at the end position, we store -h,
So that we can scan the position from left to right, at every position, we have the height above this position.
How to maintain hieght we have at x?
We create a multiset, the last one is the highest one.
When we meet the positive height, handle it, insert it into set;
When we meet the negative height, handle it, remove it from the set.

To make sure there is no duplicate interval in the result,
At the same position, the bigger height comes in front.

Times:O(nlogn),
Space:O(n).
*/

class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> a,pair<int,int> b) const {
            return a.first<b.first||(a.first==b.first&&a.second>b.second);
        }
    };
    multiset<pair<int,int>,compare> data;
    multiset<int> mheight;
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        for(auto b:buildings){
            data.insert({b[0],b[2]});
            data.insert({b[1],-b[2]});
        }
        vector<pair<int,int>> res;
        for(auto d:data){
            int h=abs(d.second);
            if(d.second>0){
                if(h>getmax()){
                    res.push_back({d.first,h});
                }
                mheight.insert(h);
            }
            else{
                //d.second<0
                auto it=mheight.find(h);
                mheight.erase(it);
                if(h>getmax()){
                    res.push_back({d.first,getmax()});
                }
            }
        }
        return res;
    }
    int getmax(){
        if(mheight.empty()) return 0;
        else return *mheight.rbegin();
    }
};