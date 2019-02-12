/*
This problem can be solved by Binary Indexed Tree or Segment Tree.

Binary Indexed Tree:
For an existing array A, we create a new array C with the same length,
to store the sum of some element of A, Details are as follows:
Elements at odd indices are the same as A, Elements at even indices are sum of some Ai.

C1=A1,
C2=A1+A2,
C3=A3,
C4=A1+A2+A3+A4,
C5=A5,
C6=A5+A6,
C7=A7,
C8=A1+A2+A3+A4+A5+A6+A7+A8,
...

How to determine what C[i] contains?
It is determined by lowest digit 1 of index's binary form.
Index       Binary      Lowest 1
1		0001		1
2		0010		2
3		0011		1
4		0100		4
5		0101		1
6		0110		2
7		0111		1
8		1000		8
For C[i], start from the A[i], in descending order, the number of elements is the lowest 1.

Trick to get lowest 1: (x&-x), 
This makes use of feature of complement code.

Now let's come to the problem:
The core Api:
update:
When A[i] is updated, we should update all elements of C that contains A[i].
Start from the index i, for the index j, the next index that contains A[i] is C[j+(j&-j)]

getsum:
Start from the C[i], for the index j, the last index that excluded from C[j] is C[j-(j&-j)],
So we sum them up, get the sum from A[1] to A[i].

Time: update:O(logn), getsum:O(logn),
Space: O(n).
*/

class NumArray {
public:
    NumArray(vector<int> nums) {
        int n=nums.size();
        data.resize(n+1);
        tree.resize(n+1);
        for(int i=0;i<n;i++) update(i,nums[i]);
    }
    
    void update(int i, int val) {
        int diff=val-data[i+1];
        for(int j=i+1;j<data.size();j+=(j&-j)){
            tree[j]+=diff;
        }
        data[i+1]=val;
    }
    
    int sumRange(int i, int j) {
        return getsum(j+1)-getsum(i);
    }
    int getsum(int i){
        int res=0;
        for(int j=i;j>0;j-=(j&-j)){
            res+=tree[j];
        }
        return res;
    }
    vector<int> data;
    vector<int> tree;
};



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
