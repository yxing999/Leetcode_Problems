/*
Build the relationship between integer and roman,
Be sure to consider the 900,400,90... etc. these are substraction situation.

Time O(n);
Space: O(1).
*/

class Solution {
public:
    vector<int> number={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num) {
        string res;
        for(int i=0;i<number.size();i++){
            int count=num/number[i];
            num%=number[i];
            while(count){
                res+=roman[i];
                count--;
            }
        }
        return res;
    }
};