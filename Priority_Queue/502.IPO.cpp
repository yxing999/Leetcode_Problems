/*
Create two heaps:
1.p_c: Store pair of profit and required capital. descending order of profit
2.c_p Store pair of capital and profit, ascending order of capital.

Push all projects to c_p,
At each k, push all projects to p_c which can be done with current W,
Choose the top one of p_c, add profit to W.
*when the heap is empty, just return current W.

Time:O(n*logn), n is length of Profits
Space:O(n)
*/

class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> a,pair<int,int> b){
            return a.first>b.first;
        }
    };
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int res=W;
        priority_queue<pair<int,int>> p_c;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> c_p;
        for(int i=0;i<Profits.size();i++){
            c_p.push({Capital[i],Profits[i]});
        }
        while(k--){
            while(c_p.top().first<=res&&!c_p.empty()){
                p_c.push({c_p.top().second,c_p.top().first});
                c_p.pop();
            }
            if(p_c.empty()) return res;
            res+=p_c.top().first;
            p_c.pop();
        }
        return res;
    }
};