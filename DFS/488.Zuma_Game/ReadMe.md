### 488.Zuma_Game:
Great problem based on a famous game.  
  
Store the balls we have in a hash map firstly.  
  
Try to add new balls at every gap of board(same color, make the three-consecutive).  
  
Clean the board to remove consecutive balls when moving to a new branch. Since we make one three-consecutive balls at one time, there will be only 1 consecutive balls(3 or more) at one clean step. So we can just return we find consecutive balls.  

Time: O(n*2^n);
Space: O(m).  n is board's size, m is hand's size.