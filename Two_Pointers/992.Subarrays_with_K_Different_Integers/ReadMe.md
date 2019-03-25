### 992.Subarrays with k Different Integers:
`Subarrays with k integers` =
`Subarrays with at most k integers` - `Subarrays with at most (k - 1) integers`  
  
Function to find number of subarrays with __AtMost__ k integers can be a template of sliding window.  
  
```C++
int subAtMostK(vector<int> &A, int K) {
        unordered_map<int, int> hash;
        int res = 0;
        int left = 0;
        
        for (int right = 0; right < A.size(); right++) {
            hash[A[right]]++;
            while (hash.size() > K) {
                hash[A[left]]--;
                if (hash[A[left]] == 0) hash.erase(A[left]);
                left++;
            }
            res += right - left + 1;
        }
        
        return res;
    }
```

`left` and `right` mark the sides of sliding window. we move right along the input array, keep the subarray between `left` and `right` has no more k different integers(If more than k after moving `right`, move `left` to the right and update hash table).  
At every position `right`, there are `right - left + 1` subarrays meet the requirements(End at `right`, start at any position in [`left`, `right`]).  
  
Time: O(n),  
Space:O(n).
