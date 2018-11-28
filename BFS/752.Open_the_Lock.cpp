/*
General BFS problem.
For every status starting from "0000", there are 8 kinds following status.
Choose those are not in deadends or visited, push them into queue.

This problem has a lot of room for improvement in runtime.

Time: O(10000);
Space:O(10000).
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead_set(deadends.begin(),deadends.end());
        if(dead_set.count("0000")) return -1;
        unordered_set<string> visited;
        queue<pair<string,int>> helper;
        helper.push({"0000",0});
        visited.insert("0000");
        while(!helper.empty()){
            auto temp=helper.front();
            helper.pop();
            if(temp.first==target) return temp.second;
            else{
                vector<string> next=findnext(temp.first,target);
                for(string str:next){
                    if(!visited.count(str)&&!dead_set.count(str)){
                        helper.push({str,temp.second+1});
                        visited.insert(str);
                    }
                } 
            }
        }
        return -1;
    }
    vector<string> findnext(string cur,string target){
        vector<string> res;
        for(int i=0;i<4;i++){
            string temp=cur;
            temp[i]=(cur[i]-'0'+1)%10+'0';
            res.push_back(temp);
            temp[i]=(cur[i]-'0'+9)%10+'0';
            res.push_back(temp);
        }
        return res;
    }
};