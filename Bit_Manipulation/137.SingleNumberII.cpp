/*
This is a follow up question of 136 Single Number,
Every number appears 3 times,
In addition, there are restrictions: linear runtime complexity, const extra space.
So I solve it on bit level.
there are several strategies, but they are all similar.
*/

/*
Int number consists of 32 bits, we loop on the array, count total number of 1 on every bit,
for the number that appears three time, they contribute 3*k 1 to this bit.
for the number that appears just once, it contributes one 1 to this bit.
make the total number of every bit modulo 3,
if we get 0, that means that bit of result is 0,
else if we get 1,that bit of result is 1.
Time :O(n)
space:O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<nums.size();j++){
                sum+=(nums[j]>>i)&1;
            }
            sum%=3;
            res|=sum<<i;
        }
        return res;
    }
};

/*
another approach is set 2 bits a, b to record, a=b=0 at start.
Loop on array, what we want is:

for the integer x we meet,
first time: a=x,b=0;
second time: a=x,b=x;
third time: a=0,b=0;
In the end, a is the result.

a=a^nums[i]&~b;
b=b^nums[i]&~b;
if you ask me how did you get this method, I got it from the website.
But I don't think it is difficult, when you are done enough exercise, God will tell you.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0,b=0;
        for(int i=0;i<nums.size();i++){
            a=a^nums[i]&~b;
            b=b^nums[i]&~a;
        }
        return a;
    }
};

