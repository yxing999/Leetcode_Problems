/*
Using istringstream or stack makes this problem every easy.
But the purpose of this problem is to solve it in place.

Time: O(n);
Space: O(1);
*/

class Solution {
public:
    void reverseWords(string &s) {
        int left=0,right=0,i=0;
        while(s[i]==' '&&i<s.size()) i++;
        if(i==s.size()){
            s.clear();
            return;
        }
        s+=' ';
        for(;i<s.size();i++){
            if(i!=0&&s[i]==' '&&s[i-1]==' ') continue;
            s[right]=s[i];
            if(s[right]==' '){
                reverse(s.begin()+left,s.begin()+right);
                left=right+1;
            }
            right++;
        }
        s.resize(right-1);
        reverse(s.begin(),s.end());
    }
};