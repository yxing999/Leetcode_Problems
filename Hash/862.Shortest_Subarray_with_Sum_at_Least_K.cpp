/*
Problem about subarray, we usually build a container to memory sum of left i numbers.
num[i]-num[j] is the sum of subarray from length j+1 to i.
For this problem, O(n^2) is bad solution.
To improve time complexity, Let's carefully think about our task:
After getting sum[i], we want to find the biggest j, where sum[j]<=sum[i]-K.
So besides the array to memory the sum, we build a map to store the num[i] and length i.
In every step, we only want the length of pair, whose sum is less than sum[i]-K,
So the pair whose key(sum) is bigger than sum[i] is useless after sum[i] is inserted.
Just erase them.

What we would get after this operation?
Every new pair contains the biggest length i so far,
and we delete all pairs, whose key(sum) is bigger than it, so the new pair is on the end of map.
Now, not only the key(sum), but also the value(length) is in ascending order.
So, we can find the biggest j in O(1) time.

Time: O(nlogn),
Space: O(n).
*/

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n=A.size();
        vector<int> sum(n+1);
        map<int,int> mp;mp[0]=0;
        int res=n+1;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+A[i-1];
            int temp=sum[i]-K;
            auto it=mp.upper_bound(temp);
            if(it!=mp.begin()){
                it--;
                res=min(res,i-it->second);
            }
            mp[sum[i]]=i;
            while(mp.rbegin()->first!=sum[i]) mp.erase(mp.rbegin()->first);
        }
        return res==n+1?-1:res;
    }
};


/*
Further time Complexity improvement:
Build a deque to store index of the sum, keep the sum[i] in the deque is in ascending order.

why ascending order?
We want the shorest subarray, whose sum is at least K,
Assume there are a<b, but nums[a]>sum[b], when we at i, 
sum[i]-sum[b] is bigger than sum[i]-sum[a],
if the latter satisfies the condition, the former is also satisfied,
also, the length of former must be shorter than latter.
So, when we get sum[b], the sum[a] is useless.

Time: O(n),
Space: O(n). 
*/

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n=A.size();
        vector<int> num(n+1);
        for(int i=1;i<=n;i++) num[i]=num[i-1]+A[i-1];
        deque<int> q;
        int res=n+1;
        for(int i=0;i<=n;i++){
            while(!q.empty()&&num[i]-num[q.front()]>=K){
                res=min(res,i-q.front());q.pop_front();
            }
            while(!q.empty()&&num[i]<=num[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return res==n+1?-1:res;
    }
};
