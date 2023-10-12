class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size() - 1, n = nums.size(), flag = n;
        for(int i=0; i<n && i<=right; ++i) {
            while(right > 0 && nums[right] == val) {
                --right;
                --flag;
            }
            if(nums[i] == val && i <= right) {
                swap(nums[i], nums[right--]);
                --flag;
            }
        }

        return flag;
    }
};