/*
This problem's solution can be regarded as a template for sliding window, using two pointers.
First, build a hashmap to memorize characters and frequency of t.
Then scan s, reduce frequency of every character by 1. 
If frequency is bigger than 0, which means it is one of string t, we reduce m by 1.
When m equals 0, which means the window between left and right contains all characters of t,
but not the minimum necessarily. we should increase left until one of character of t.
If this is a minimum substring now, record it by start and len.

some edge cases:
1.t.size()==0.
  Result should be "". it is better to add a line to handle this, executing this function with m=0 is ugly.
2.s.size()==0;
  this function will return "", which is reasonable.
  
Time: O(n), n is length of s;
Space: O(m), m is length of t.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.size();
        if(m==0) return "";
        unordered_map<char,int> char_t;
        for(char ch:t) char_t[ch]++;
        int len=INT_MAX;
        int start=0,left=0;
        for(int right=0;right<s.size();right++){
            if(char_t[s[right]]-- >0) m--;
            if(m==0){
                while(char_t[s[left]]<0){
                    char_t[s[left]]++;
                    left++;
                }
                if(right-left+1<len){
                    len=right-left+1;
                    start=left;
                }
                char_t[s[left]]++;
                left++;
                m++;
            }
        }
        return len==INT_MAX? "":s.substr(start,len);
    }
};