/*
We need two pass to find this two result numbers, we assume they are num1,num2.
First pass: Set a b=0, make b xor every num of nums, finally, b=num1^num2.
            then we executed b=b&-b, this is a fixed way to keep only the right most 1 of b.
            ***
            In the computer, negative integer is represented by complement code.
            ***
            since num1 and num2 are different, that 1 must exist.
Second pass:Since b=num1^num2. for the bit that equals 1.
            num1 and num2 at that position must be a 0 and a 1 respectively.
            So we use num&b==0 to divide them. 
            we don't care about other num, XOR twice always get 0.
Time: O(n);
Space: O(1).
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int b=0;
        for(int num:nums)
            b^=num;
        b&=-b;
        vector<int> res={0,0};
        for(int num:nums){
            if((num&b)==0) res[0]^=num;
            else res[1]^=num;
        }
        return res;
    }
};
