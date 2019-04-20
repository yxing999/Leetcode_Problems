/*
See 25ml as a single part, solve this problem recursively.
Create a 2D array to memorize the result of status (a,b).

A is easier to become empty than B, so when N is big enough, the result must be 1.
follow the recursion, we can find the Threshold is 4800.

Time: O(n^2),
Space: O(1).
*/

class Solution {
public:
    double memo[200][200];
    double soupServings(int N) {
        if(N>4800) return 1;
        else return recursion((N+24)/25,(N+24)/25);
    }
    double recursion(int a,int b){
        if(a<=0&&b<=0) return 0.5;
        else if(a<=0) return 1.0;
        else if(b<=0) return 0;
        else if(memo[a][b]>0) return memo[a][b];
        memo[a][b]=0.25*(recursion(a-4,b)+recursion(a-3,b-1)+recursion(a-2,b-2)+recursion(a-1,b-3));
        return memo[a][b];
    }
};


//another version, with the same strategy.
namespace std{
        template<> struct hash<pair<int, int>>{
            size_t operator()(const pair<int, int> &p) const{
                return hash<int>()(p.first)^hash<int>()(p.second);
            }
        };
    }
class Solution {
public:
    unordered_map<pair<int, int>, double> hash;
    double soupServings(int N) {
        if (N > 4800) return 1;
        return recursion(N, N);
    }
    
    double recursion(int a, int b)
    {
        if (a <= 0 && b <= 0) return 0.5;
        else if (a <= 0 && b > 0) return 1;
        else if (a > 0 && b <= 0) return 0;
        else if(hash.count({a, b})) return hash[{a,b}];
        else {
            hash[{a,b}] = 0.25 * (recursion(a - 100, b) + recursion(a - 75, b - 25) + recursion(a - 50, b - 50) + recursion(a - 25, b - 75));
            return hash[{a, b}];
        }
    }
};
