/*
Divide the string into two parts: length of i and n-i.
These two parts can be reversed or not.
Do judgement recursively, layer by layer.
Only strings contains the same character set can be scramble, judge this by a hashmap before for loop,
this will save a lot of runtime.

Time: O(2^n),
Space:O(n).
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        if(n==0) return true;
        if(n==1) return s1==s2;
        unordered_map<char,int> hash;
        for(char ch:s1) hash[ch]++;
        for(char ch:s2) hash[ch]--;
        for(auto a:hash) if(a.second!=0) return false;
        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))
                return true;
            else if(isScramble(s1.substr(0,i),s2.substr(n-i))&&isScramble(s1.substr(i),s2.substr(0,n-i)))
                return true;
        }
        return false;
    }
};
