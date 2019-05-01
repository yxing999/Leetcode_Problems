### 632.Smallest Range:
This problem requires us to find a smallest range covering at least one number from each of the list.  
Covering one must be better or equal to covering more than one, so we cover one number from every list.  

The strategy is:  
We build an ascending list from the first number of every list, by priority_queue.  
`[a, b, c, ..., d]`  
the current range is `[a, d]`,  
Then we update this list by replace number by next bigger number. Only replace `a` (smallest number of this list)can we get a smaller range.  
So, we keep replacing smallest number and track the range, until we reach the end of one input num.  

Time: O(n*logn),  
Space: O(n).  
`n` is the count of input numbers.