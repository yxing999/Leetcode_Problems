'''
An algorithm invented by Boyer-Moore.
The number of three-majority element can be at most 2.
So, we loop on nums, when we get three distinct elements, remove them all,
This removal doesn't affact the possible majority elements.

The two remaining elements are the most frequent elements,
Count their frequency, if it is bigger than ⌊ n/3 ⌋, return it.

Time: O(n),
Space: O(1).
'''

class Solution:
    def majorityElement(self, nums: 'List[int]') -> 'List[int]':
        n = len(nums)
        r1, t1, r2, t2 = 0, 0, 0, 0
        #find the two most frequent numbers
        for i in nums:
            if i == r1:
                t1 += 1
            elif i == r2:
                t2 += 1
            elif t1 == 0:
                r1 = i
                t1 = 1
            elif t2 == 0:
                r2 = i
                t2 = 1
            else:
                t1 -= 1
                t2 -= 1
        
        n1, n2 = 0, 0
        for i in nums:
            if i == r1:
                n1 += 1
            elif i == r2:
                n2 += 1
        
        res=[]
        if n1 > n // 3:
            res.append(r1)
        if n2 > n // 3:
            res.append(r2)
        return res