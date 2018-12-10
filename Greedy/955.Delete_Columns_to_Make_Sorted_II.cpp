/*
Scan the column from the left to right.
In each column i, if we find A[j][i]>A[j+1][i], delete this column, res++;
if every A[j][i]<A[j+1][i], just return the res.

The most trouble case is, some A[j][i]==A[j+1][i].
we build a array of bool to store the sorted row(A[j][i]<A[j+1][i]),
if this row is sorted at i column, the subsequent order doesn't matter.
so we only handle the unsorted row in the subsequent columns.

Time: O(mn),
Space: O(m).
*/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res=0;
        int m=A.size(),n=A[0].size();
        vector<bool> sorted(m-1,false);
        bool hasequal;
        for(int i=0;i<n;i++){
            int j;
            hasequal=false;
            for(j=0;j<m-1;j++){
                if(!sorted[j]&&A[j][i]>A[j+1][i]){
                    res++;
                    break;
                }
                else if(!sorted[j]&&A[j][i]==A[j+1][i]) hasequal=true;
            }
            if(!hasequal&&j==m-1) return res;
            if(j<m-1) continue;
            for(j=0;j<m-1;j++){
                if(A[j][i]<A[j+1][i])
                    sorted[j]=true;
            }
        }
        return res;
    }
};