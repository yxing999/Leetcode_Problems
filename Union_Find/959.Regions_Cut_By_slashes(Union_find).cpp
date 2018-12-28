/*
Split every region into 4 parts:
 __
|\/|
|/\|
 --
Make the corresponding relationship between parts and numbers:
top:0,right:1,bottom:2,left:3.
So, there are n*n*4 parts in the grid.

At the beginning, we assume every slash exists,Then we loop on the grid.

if i>0, we connect the part 0 of grid[i][j] and part 2 of grid[i-1][j],
if j>0, we connect the part 3 of grid[i][j] adn part 1 of grid[i-1][j].
These are initial state.

if grid[i][j] is not '/',we get:
 __
|\ |
| \|
 --
So we connect part 0 and 1, 2 and 3;
if grid[i][j] is not '\\', we get:
 __
| /|
|/ |
 --
So we connect part 0 and 3, 1 and 2.
This strategy includes the case grid[i][j]==' ', making the code clean.

Time: O(n^2),
Space: O(n^2).
*/

class Solution {
public:
    int count,n;
    vector<int> root;
    int regionsBySlashes(vector<string>& grid) {
        n=grid.size();
        count=n*n*4;
        for(int i=0;i<count;i++) root.push_back(i);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>0) connect(g(i-1,j,2),g(i,j,0));
                if(j>0) connect(g(i,j-1,1),g(i,j,3));
                if(grid[i][j]!='/'){
                    connect(g(i,j,0),g(i,j,1));
                    connect(g(i,j,2),g(i,j,3));
                }
                if(grid[i][j]!='\\'){
                    connect(g(i,j,0),g(i,j,3));
                    connect(g(i,j,1),g(i,j,2));
                }
            }
        }
        return count;
    }
    int find(int i){
        if(root[i]!=i) root[i]=find(root[i]);
        return root[i];
    }
    void connect(int i,int j){
        int rooti=find(i);
        int rootj=find(j);
        if(rooti!=rootj){
            root[rooti]=root[rootj];
            count--;
        }
    }
    int g(int i,int j,int k){
        return (i*n+j)*4+k;
    }
};