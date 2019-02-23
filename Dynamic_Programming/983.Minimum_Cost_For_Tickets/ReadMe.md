### 983.Minimum Cost for Tickets:
Loop on input array,  
At each day i, Look backward at days:  
`one_ago`: one day ago,  
`seven_ago`: seven days ago,  
`thirty_ago`: thirty days ago.  
  
Buy:  
1-day pass after one_ago,  
7-day pass after seven_ago,  
30-day pass after thirty_ago.  
choose the minimum cost as the cost at day i.

Time:O(nlogn),
Space:O(n).
