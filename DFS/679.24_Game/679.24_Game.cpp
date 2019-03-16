class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        if (four(nums)) return true;
        while (next_permutation(nums.begin(), nums.end())) {
            if (four(nums)) return true;
        }
        
        return false;
    }
    
    bool four(vector<int> &nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (three(a + b, c, d) || three(a, b + c, d) || three(a, b, c + d)) return true;
        if (three(a - b, c, d) || three(a, b - c, d) || three(a, b, c - d)) return true;
        if (three(a * b, c, d) || three(a, b * c, d) || three(a, b, c * d)) return true;
        if (three(a / b, c, d) || three(a, b / c, d) || three(a, b, c / d)) return true;
        return false;
    }
    
    bool three(double a, double b, double c) {
        if (two(a + b, c) || two(a, b + c)) return true;
        if (two(a - b, c) || two(a, b - c)) return true;
        if (two(a * b, c) || two(a, b * c)) return true;
        if (two(a / b, c) || two(a, b / c)) return true;
        return false;
    }
    
    bool two(double a, double b) {
        if (abs(a + b - 24.0) < diff || abs(a - b - 24.0) < diff || abs(a * b - 24.0) < diff || abs(a / b - 24.0) < diff) return true;
        return false;
    }
private:
    double diff = 0.0001;
};