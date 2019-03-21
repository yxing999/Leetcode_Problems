class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
    
    int mergesort(vector<int> &nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int res = mergesort(nums, left, mid) + mergesort(nums, mid + 1, right);
        for (int i = left, j = mid + 1; i <= mid; i++) {
            while (j <= right && (long)nums[i] > 2 * (long)nums[j]) j++;
            res += j - (mid + 1);
        }
        merge(nums, left, mid, right);
        return res;
    }
    
    void merge(vector<int> &nums, int left, int mid, int right) {
        int n1 = mid - left + 1, n2 = right - mid;
        int L[n1], R[n2];
        for (int i = left; i <= mid; i++)
            L[i - left] = nums[i];
        for (int i = mid + 1; i <= right; i++)
            R[i - (mid + 1)] = nums[i];
        int i = 0, j = 0;
        for (int k = left; k <= right; k++){
            if (j >= n2 || (i < n1 && L[i] < R[j])) nums[k] = L[i++];
            else nums[k] = R[j++];
        }
    }
};
