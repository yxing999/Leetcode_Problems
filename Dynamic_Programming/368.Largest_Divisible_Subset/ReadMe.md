Sort the input nums, because if 'A' can be divided by 'B', 'A' can also be divided by 'B' 's divisors.  
Create a 'dp' array, each element is a pair, containing last index of divisor and length of divisible subset until now.  
At index i, scan all previous elements of 'dp':  
Find the divisible numbers and choose the largest one, update 'dp', record the largest subset until now in 'maxlen'.  
'maxlen' records the index.  
After that, insert the largest subset into 'res'.  

Time:O(n^2),  
Space:O(n).