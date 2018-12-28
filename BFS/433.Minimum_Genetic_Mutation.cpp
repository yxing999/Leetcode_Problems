/*
Almost the same problem to 127.Word Ladder.
Using BFS, on every layer, find the string whose distance with current string is 1,
Mark the string we visited.

Time: O(m*n),
Space: O(m*n). n is length of banks, m is length of string.
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int> visited;
        for(auto s:bank) visited[s]=0;
        int res=0;
        queue<string> q;
        q.push(start);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string temp=q.front();q.pop();
                cout<<temp<<" ";
                if(temp==end) return res;
                for(auto ele:visited){
                    if(dif(temp,ele.first)==1&&!ele.second){
                        q.push(ele.first);
                        visited[ele.first]++;
                    }
                }
            }
            res++;
        }
        return -1;
    }
    int dif(string a,string b){
        int count=0;
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i]) count++;
        return count;
    }
};