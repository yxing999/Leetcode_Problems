/*
Sort the tokens, in every step, 
use smallest to get point, if P is not enough, use largest to get P. 
store the maximum point after every getting point.

Time: O(nlogn),
Space: O(1).
*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int res=0,cur_point=0;
        int i=0,j=tokens.size()-1;
        while(i<=j){
            if(P>=tokens[i]){
                P-=tokens[i++];
                cur_point++;
                res=max(res,cur_point);
            }
            else if(cur_point>0){
                P+=tokens[j--];
                cur_point--;
            }
            else break;
        }
        return res;
    }
};