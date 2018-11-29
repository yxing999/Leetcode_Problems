/*
Starting from the beginWord, push all words into queue whose distance to current word is 1.
until we find the endWord.

Two things need attention:
1.How to find the words with 1 distance? 
  Change every char of word, from 'a' to 'z', and see if it is in the word set.
2.Remember to remove words from set after pushing into queue. we don't want to go back.

Time: O(n*m), 
Space: O(n*m). n is wordList's size, m is every string's length
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(),wordList.end());
        queue<string> help;
        help.push(beginWord);
        int res=0;
        while(!help.empty()){
            int n=help.size();
            while(n--){
                string temp=help.front(); help.pop();
                if(temp==endWord) return res+1;
                for(int i=0;i<temp.size();i++){
                    string cur=temp;
                    for(int k=0;k<26;k++){
                        cur[i]='a'+k;
                        if(word_set.count(cur)) {
                            help.push(cur);
                            word_set.erase(cur);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};