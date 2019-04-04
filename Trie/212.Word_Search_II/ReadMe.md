### 212.Word Search II :
Firstly, we need to build a [Trie](https://en.wikipedia.org/wiki/Trie) to represent input words.  
Trie will reduce the time complexity to traverse words with the same prefix.  

We loop on the input board, at each cell `board[i][j]`, we try to match the Trie we build previously. Implement DFS, to avoid duplicates, we build a set to remember matched string.  

As for time and space complexity, 我脑壳疼。