/*
Do not stick to each single bar, regard the whole system as a big pond.
How much water can a bar hold on it?
It depends on the highest bar on its left and right.

Time: O(n);
Space: O(n).
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        
        vector<int> leftmost(n);
        vector<int> rightmost(n);
        
        for(int i=1;i<n;i++) leftmost[i]=max(leftmost[i-1],height[i-1]);
        for(int i=n-2;i>=0;i--) rightmost[i]=max(rightmost[i+1],height[i+1]);
        
        int res=0;
        for(int i=1;i<n-1;i++){
            int temp=min(leftmost[i],rightmost[i])-height[i];
            res+=temp>0?temp:0;
        }
        return res;
    }
};