/*
This is a typical problem of Union Find.
It can be classified to number of island.
It is not complex after realizing to implement Union_Find.
Scan all pairs of stones, connect them if they share row or column(merge them into one set).
the result in the end is number of stones minus number of sets.

Time Complexity:
The time complexity consists of two parts:
1.Two for loops. O(n^2)
2.Connect operations in every step. O(logn)
Time: O(n^2*logn).
***
Due to my limit on mathematics, I am not sure about this yet, correctness or rigor.
***

Space: O(n).
*/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int count=n;
        vector<int> union_array(n);
        for(int i=0;i<n;i++) union_array[i]=i;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++)
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                    connect(union_array,i,j,count);
        }
        return n-count;
    }
    int find(vector<int> &union_array,int x){
        if(union_array[x]==x) return x;
        return find(union_array,union_array[x]);
    }
    void connect(vector<int> &union_array,int i,int j,int &count){
        int rooti=find(union_array,i);
        int rootj=find(union_array,j);
        if(rooti!=rootj) {
            union_array[rooti]=rootj;
            count--;
        }
    }
};

/*
Solution with less time complexity:
Connecting every stone wastes time, we can connect x and y of every stone.
So the time Complexity of for loop becomes O(n),
One thing to handle: 
we cannot tell if a number is x or y, a easy trick is add 10000 to y,
since the range of x and y is [0,10000), so the new range of y is [10000,20000).

Time: O(n*longn);
Space: O(20000).
*/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> parent(20000);
        for(int i=0;i<20000;i++) parent[i]=i;
        for(auto stone:stones) connect(parent,stone[0],stone[1]+10000);
        unordered_set<int> count;
        for(auto stone:stones) count.insert(find(parent,stone[0]));
        return n-count.size();
    }
    int find(vector<int> &parent, int x){
        if(parent[x]==x) return x;
        else return find(parent,parent[x]);
    }
    void connect(vector<int> &parent,int x,int y){
        parent[find(parent,x)]=find(parent,y);
    }
};