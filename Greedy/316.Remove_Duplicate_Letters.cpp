/*
Create a hash table to memorize the number of every letter,
Also create a hash table to record whether a letter is visited.

Strategy:
Loop on string s, substrct 1 from the number of current letter,
if the current letter is visited(this letter is arranged before), move to the next letter;
else, if the ASCII value of current letter is bigger than the last letter in the res,
and the c[res.back()]>0 (there is still this letter following),
we remove the back letter, mark is as unvisited.
This is the key process to guarantee smallest lexicographical order.

A trick to make code clear: add a '0' at the beginning of the res,
Since '0''s ASCII value is smaller than any letter, it won't affect the result,
but helps us to do the compare of the first letter.

Time: O(n),
Space: O(1).
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> c;
        unordered_map<char,int> visited;
        string res="0";
        for(char ch:s) c[ch]++;
        for(char ch:s){
            c[ch]--;
            if(visited[ch]) continue;
            while(res.back()>ch&&c[res.back()]>0){
                visited[res.back()]=0;
                res.resize(res.size()-1);
            }
            res+=ch;
            visited[ch]=1;
        }
        return res.substr(1,res.size()-1);
    }
};