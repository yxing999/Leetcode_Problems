/*
Good problem. Include not only union find, but also math.
The time limit is very strict.
The following solution can pass barely. the runtime is int the back of all submissions.

First, Find all primes within max element of A.
Then union every element with its primes.
Finally, return the largest component.

Time: O(n*w), w is the length of primes.
Space: O(w).
*/

class Solution {
public:
    unordered_map<int,int> root;
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end());
        vector<int> primes=make_primes(n);
        for(int p:primes) root[p]=p;
        for(int a:A) root[a]=a;
        
        for(int a:A){
            for(int p:primes){
                if(p>a/2) break;
                if(a%p==0&&findroot(a)!=findroot(p))
                    connect(a,p);
            }
        }
        unordered_map<int,int> component;
        for(int a:A) component[findroot(a)]++;
        int res=0;
        for(auto ele:component) res=max(res,ele.second);
        return res;
    }
    vector<int> make_primes(int n){
        vector<bool> isprime(n,true);
        vector<int> res;
        for(long i=2;i<n;i++){
            if(isprime[i]){
                res.push_back(i);
                for(long j=i*i;j<n;j+=i)
                    isprime[j]=false;
            }
        }
        return res;
    }
    int findroot(int i){
        if(root[i]!=i) root[i]=findroot(root[i]);
        return root[i];
    }
    void connect(int i,int j){
        int rooti=root[i];
        int rootj=root[j];
        if(rooti<rootj) root[rootj]=rooti;
        else root[rooti]=rootj;
    }
};

/*
we connect a with factors of a, from 2 to sqrt(a),
Which will reduce the time complexity from n to sqrt(n).

The trick is, if i is a's factor, a/i must be a's factor.

Time: O(N*sqrt(n)), N is length of A, n is the max number of A.
Space: O(n).
*/

class Solution {
public:
    vector<int> root;
    int largestComponentSize(vector<int>& A) {
        int n=*max_element(A.begin(),A.end());
        root.resize(n+1);
        for(int i=0;i<=n;i++) root[i]=i;
        for(int a:A){
            for(int i=2;i<=sqrt(a);i++){
                if(a%i==0){
                    connect(a,i);
                    connect(a,a/i);
                }
            }
        }
        unordered_map<int,int> component;
        int res=0;
        for(int a:A) res=max(res,++component[findroot(a)]);
        return res;
    }
    int findroot(int i){
        if(root[i]!=i) root[i]=findroot(root[i]);
        return root[i];
    }
    void connect(int i,int j){
        root[findroot(i)]=root[findroot(j)];
    }
};