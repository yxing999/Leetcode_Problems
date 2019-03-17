/*
The input size is very small, 
So we can implement backtracking to enumerate all possible cases.
The time complexity is on exponential level.
Space: O(n),n is the size of price.
*/

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=price.size();
        int res=INT_MAX,cur_price=0;
        vector<int> cur(n,0);
        DFS(price,special,needs,cur,res,cur_price,0);
        return res;
    }
    void DFS(vector<int>& price, vector<vector<int>>& special,vector<int>& needs,vector<int> &cur, int &res,int &cur_price,int k){
        if(!smaller(cur,needs)){
            return;
        }
        int t=cur_price;
        for(int p=0;p<price.size();p++){
            t+=price[p]*(needs[p]-cur[p]);
        }
        res=min(res,t);
        for(int i=k;i<special.size();i++){
            int temp=special[i].back();
            for(int j=0;j<price.size();j++) cur[j]+=special[i][j];
            cur_price+=temp;
            DFS(price,special,needs,cur,res,cur_price,i);
            for(int j=0;j<price.size();j++) cur[j]-=special[i][j];
            cur_price-=temp;
        }
    }
    bool smaller(vector<int> a,vector<int> b){
        for(int i=0;i<a.size();i++){
            if(a[i]>b[i]) return false;
        }
        return true;
    }
};