class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid - 1 >= lo && nums[mid] < nums[mid - 1]) {
                hi = mid - 1;
            } else if (mid + 1 <= hi && nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return lo;
    }
};