/*
We scan from right to left, count the smaller numbers we have passed.
If we count the number directly, the time complexity will be n^2.
So we make use of a useful data structure - Binary Indexed Tree(refer to LC 307).
BIT is used to get sum of first i-th elements in O(logn).

How to apply BIT to this problem?
1.Sort the input nums, find the rank of every distinct number among the array.
  for example: [5,2,6,1]->[1,2,5,6]->(rank)[1,2,3,4]
2.Create a BIT, size is the number of distinct elements plus one.
3.Scan the input array from the right, at current element nums[i],
  get its rank, count sum of first (i-1)-th rank, this is the result at i.
  update the BIT at i by 1.

Time:O(n*logn)
Space:O(k),k is the number of distinct numbers.
*/

class BIT{
public:
    BIT(int n): tree(n+1,0) {}
    void update(int i,int diff){
        while(i<tree.size()){
            tree[i]+=diff;
            i+=lowbit(i);
        }
    }
    int query(int i){
        int res=0;
        while(i>0){
            res+=tree[i];
            i-=lowbit(i);
        }
        return res;
    }
private:
    inline int lowbit(int k) { return k&-k; }
    vector<int> tree;
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> order(nums.begin(),nums.end());
        unordered_map<int,int> rank;
        int r=0;
        for(auto i:order) rank[i]=++r;
        
        BIT bit= BIT(r);
        vector<int> res(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            int k=nums[i];
            res[i]=bit.query(rank[k]-1);
            bit.update(rank[k],1);
        }
        return res;
    }
};