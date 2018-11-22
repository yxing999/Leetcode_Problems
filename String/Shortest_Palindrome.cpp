/*
We can only add characters in front of s.
So we can find longest palindrome from the left of s, 
and then add the reverse of the rest in front of s.
Time:O(n), if considering the compare time, it is o(n^2) actually.
Space:O(n).
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        int i;
        for(i=n;i>0;i--){
            if(s.substr(0,i)==t.substr(n-i))    
                break;
        }
        return t.substr(0,n-i)+s;
    }
};

/*
The above solution is easy to implement, but the compare between two strings wastes too much time.
KMP algorithm improves the runtime significantly.
The same goal, we want to find longest palindrome from the left of s,
So we built a new string, s+'.'+t, t is reverse of s, 
the dot is used to avoid overlap of prefix and suffix, which is not we want in this problem.
KMP algorithm is to find longest prefix which is also suffix,
This prefix is also the longest palindrome from the left of s.
Time:O(n)
Space:O(n)
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        string kmp=s+'.'+t;
        int n=kmp.size();
        vector<int> next(n,0);
        int len=0,i=1;
        while(i<n){
            if(kmp[i]==kmp[len])
                next[i++]=++len;
            else{
                if(len==0)
                    next[i++]=0;
                else
                    len=next[len-1];
            }
        }
        int rest=s.size()-next[n-1];
        return t.substr(0,rest)+s;
    }
};