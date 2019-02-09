/*
A medium problem about string.
To simplify the input string, we should extract elements out of '/'s.
for every element btween '/'s or on the front or end:
if it is a directory name, push it into the stack,
it it is a "..", "." or "", handle it according to relevant rules.
In the end, construct the result string from the stack we built just now.

Time: O(n),
Space: O(n).
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir;
        int i=0;
        string res="";
        while(i<path.size()){
            while(i<path.size()&&path[i]=='/') i++;
            string temp;
            while(i<path.size()&&path[i]!='/') temp+=path[i++];
            if(temp==".."&&!dir.empty()) dir.pop();
            else if(temp!="."&&temp!=".."&&temp!="") dir.push(temp);
        }
        if(dir.empty()) return "/";
        else{
            while(!dir.empty()){
                res="/"+dir.top()+res;
                dir.pop();
            }
        }
        return res;
    }
};