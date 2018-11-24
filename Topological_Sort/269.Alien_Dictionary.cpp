/*
Get the new lexicographic order from an array of string,
When you modeling to topological sort, you are on the half way to succeed.
Build the graph and indegree array, implement BFS.
Find the zero-indegree nodes in every step, update the indegree of following nodes.

But more than ordinary topological sort, Here are some more things to be considered.
1.The input may give us duplicate relationships, we should only count it once.
  For example: ["za","zb","ca","cb"] will give us two 'a->b'.
  but we should build the graph a->b, not a->b
  										                     \
  										                      b
2.What is definition of "valid"?
  After testing, "valid" means all characters appeared in the input should get the order in the result.
  So if a character has no relationship with others, we put it anywhere in the result.
  For example: input: ["z","z"], output:"z".
  To test the validity, We implemented a set, to hold all characters of the input.
  the result is valid only if this set and result are equal in size. 

Time:O(n),
Space:O(n). n is number of distinct characters.
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,unordered_set<char>> char_order;
        unordered_set<char> char_db;
        vector<int> indegree(26,0);
        for(auto str:words) char_db.insert(str.begin(),str.end());
        for(int i=0;i<words.size()-1;i++){
            int len=min(words[i].size(),words[i+1].size());
            for(int j=0;j<len;j++){
                if(words[i][j]!=words[i+1][j]){
                    char_order[words[i][j]].insert(words[i+1][j]);
                    break;
                }
            }
        }
        for(auto ele:char_order)
            for(char ch:ele.second)
                indegree[ch-'a']++;
        
        queue<char> que;
        for(auto ch:char_db){
            if(indegree[ch-'a']==0)
                que.push(ch);
        }
        string res;
        while(!que.empty()){
            char temp=que.front();
            que.pop();
            res+=temp;
            for(auto ch:char_order[temp]){
                if(--indegree[ch-'a']==0)
                    que.push(ch);
            }
        }
        return res.size()==char_db.size()?res:"";
    }
};
