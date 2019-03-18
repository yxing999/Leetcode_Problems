### 282.Expression Add Operators:
Try to add `+`, `-`, `*` at every position.  
At position `pos`, we loop from `pos + 1` to `n`, implement DFS, because a number may be composed by multiple digits.  
  
The main part of DFS function is :  
```
for i in range(pos + 1, n + 1) :
    str_add = num[pos, i]
    DFS(+str_add)
    DFS(-str_add)
    DFS(*str_add)
```

To implement DFS, at position `pos`, we need to maintain some attributions:  
`cur_str`: current expression we get.  
`pre_num`: last number we have(explain in detail later).  
`cur_val`: value of current expression.  
  
This three attributions will update according to the operator and number we add at position `pos`.  
`+`: `cur_str`->`cur_str + add_str`,  
    &nbsp;&nbsp;&nbsp;&nbsp;`pre_num`->`add_num`,  
    &nbsp;&nbsp;&nbsp;&nbsp;`cur_val`->`cur_val + add_num`,  
`-`: `cur_str`->`cur_str - add_str`,  
    &nbsp;&nbsp;&nbsp;&nbsp;`pre_num`->`-add_num`,  
    &nbsp;&nbsp;&nbsp;&nbsp;`cur_val`->`cur_val - add_num`,  
`*`: `cur_str`->`cur_str * add_str`,  
    &nbsp;&nbsp;&nbsp;&nbsp;`pre_num`->`pre_num * add_num`,  
    &nbsp;&nbsp;&nbsp;&nbsp;`cur_val`->`cur_val - pre_num + pre_num * add_int`,  
  
Here is a table to illustrate above three attributions:  

| cur_str | pre_num | cur_val | add_num | add_operator | cur_str*  | pre_num* | cur_val* |
| ------- | ------- | ------- | --------| ------------ | --------- | -------- | -------- |
| 2+3 | +3 | 5 | 4 | + | 2+3+4 | +4 | 9 |
| 2+3 | +3 | 5 | 4 | - | 2+3-4 | -4 | 1 |
| 2+3 | +3 | 5 | 4 | * | 2+3*4 | 3*4 | 14 |

Time: O(4^n),  
Space: O(n).


