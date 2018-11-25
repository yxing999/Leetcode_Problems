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
Time: O(logn*n^2).
***
Due to the limit on mathematics, I am not sure about this yet, correctness or rigor.
I will think about this carefully when I have time.
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