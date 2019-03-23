### 1015.Numbers with Repeated Digits:
It is complicated to find all numbers with repeated digits, because repeated digits can be 2, 3, 4, ...  
So, We find all numbers without repeated digits, then subtract them from N.  

To handle the edge case, we find all numbers smaller than N + 1.  

Assume `n` is the length of integer.  
`permutation(n, m)` is number of permutation that choose m out of n.  

Those numbers consists of two parts:  
#### part 1:
All numbers with length less than n must smaller than n, so we just count the permutation:  
```C++
for (int i = 1; i < n; i++) {
    res += 9 * permutation(9, i - 1);
}
```  

#### part 2:
The most complicated part.  
We need to make sure those numbers are not only less than N + 1, but also cannot be repeated.  

convert N + 1 to array `digits`.  

We count digit by digit, from left to right.  
At digit `i`, We try to put integers that has not been used before `i` and is between `0` and `digits[i] - 1`.  
Before `i`, we have used `i` integers, plus this digit, we have used `i + 1` integers, we have `10 - (i + 1)` integers left, and we have `n - (i + 1)` digits to arrange, so the number in this step is `permutation(9 - i, n - i - 1)`.  
When we finish this digit, if `digits[i]` is not used, set this digit to `digits[i]`, move to the next digit; if `digits[i]` is used, that means we have counted all numbers at this digit, there is no need to move to following digits, just break the for loop.

An example to illustrate:  
digits = [5, 4, 3, 2]  
We count:  
1XXX - 4XXX,\
50XX - 53XX,\
540X - 542X,\
5430 - 5431.

Notice: the head digit cannot be 0 while others can.

Time: O(log(N)),  
Space: O(n).