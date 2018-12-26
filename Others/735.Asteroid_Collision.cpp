/*
Loop on input array, only one case will cause a collision:
left is positive and right is negative.

Time: O(n),
Space: O(n).
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0||res.empty()||res.back()<0) 
                res.push_back(asteroids[i]);
            else if(res.back()<=-asteroids[i]){
                if(res.back()<-asteroids[i]) i--;
                res.pop_back();
            }
        }
        return res;
    }
};