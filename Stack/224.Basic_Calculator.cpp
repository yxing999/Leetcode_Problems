/*
Loop on the string, handle it based on the char we meet.
1.If we meet digits, add it to cur_sum.

2.If we meet operator('+' or '-'): adjust the cur_sum by current sign, add the cur_sum to res,
  reset the cur_sum to 0, set the sign to 1 or -1 for next cur_sum.
  ***the '+' or '-' determines the sign of next cur_sum. 

3.If we meet '(', we push the res and sign to the stack, 
  start a new res, for the result of content between '(' and ')'.

4.If we meet ')', we calculate the res between '(' and ')',
  then add the to the previous result, which we stored in the stack.

Time: O(n),
Space: O(n).
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> pre_res;
        int cur_sum=0,sign=1;
        int res=0;
        for(char ch: s){
            if(isdigit(ch)) cur_sum=10*cur_sum+(ch-'0');
            else{
                switch(ch){
                    case '+':
                        cur_sum=sign*cur_sum;
                        res+=cur_sum;
                        cur_sum=0;
                        sign=1;
                        break;
                    case '-':
                        cur_sum=sign*cur_sum;
                        res+=cur_sum;
                        cur_sum=0;
                        sign=-1;
                        break;
                    case '('://start a new part
                        pre_res.push(res);
                        pre_res.push(sign);
                        res=0;
                        sign=1;
                        cur_sum=0;
                        break;
                    case ')':
                        cur_sum=sign*cur_sum;
                        res+=cur_sum;//this is the res within this parentheses.
                        res*=pre_res.top();pre_res.pop();
                        res+=pre_res.top();pre_res.pop();
                        cur_sum=0;
                }
            }
        }
        res+=sign*cur_sum;
        return res;
    }
};