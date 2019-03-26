/*
Make use of polar coordinates, generate to random parameters: thera, r.
theta is evenly distributed on [0,2*pi),
But as for the r, if we distribute r on [0,radius], 
the points will get sparse as the r increase, because the area is porportional to r^2,
In order to make points evenly on r^2, not r, we need to generate r on [0,sqrt(radius)].
then the r^2 is on [0,radius], evenly.

Time:O(1),
Space:O(1).
*/

class Solution {
public:
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double theta=2*M_PI*((double)rand()/RAND_MAX);
        double l=r*sqrt((double)rand()/RAND_MAX);
        return {x+l*cos(theta),y+l*sin(theta)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */