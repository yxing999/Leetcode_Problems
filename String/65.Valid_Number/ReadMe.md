### 65.Valid Number:
A very very good problem for an interview.  
The biggest difficulty of this problem is you need to think of all criteria of valid number. Then judge it straightforwardly.  

valid number may contains following characters:  
  * Number `'0'-'9'`  
  * exponent `'e'`  
  * Positive/Negative sign `'+'/'-'`  
  * Decimal point `'.'`  


 Judgement criteria about valid characters:  
 \
 `'e'`: Input string must contain zero or one `'e'`.  
&nbsp; &nbsp; &nbsp; &nbsp; 
        the numbers between `'e'` cannot be empty.  
&nbsp; &nbsp; &nbsp; &nbsp; 
        the exponent part must be an integer.  
\
`'+'/'-'`: If have, must at the first position of                each part.  
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 
           Cannot exist alone.  
\
`'.'`: Can only occur at base part, once.  
&nbsp; &nbsp; &nbsp; &nbsp; 
       Head or trailing position is fine.  
\
Space is only allowed at head or trailing.  

Time: O(n),  
Space: O(n).  