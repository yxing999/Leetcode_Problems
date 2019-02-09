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
        string res="";
        unordered_map<char,int> hash;
        for(auto ch:t) hash[ch]++;
        int len=INT_MAX;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]-- >0) m--;
            while(m==0){
                if(++hash[s[start]]>0){
                    if(i-start<len){
                        len=i-start;
                        res=s.substr(start,i+1-start);
                    }
                    m++;
                }
                start++;
            }
        }
        return res;
    }
};