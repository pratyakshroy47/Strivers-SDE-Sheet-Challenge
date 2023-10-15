class Solution {
public:
    bool canJump(vector<int>& nums) {
        int result = 0, n = nums.size();
        for(int i=0; i<n; ++i) {
            if(i <= result) {
                result = max(i + nums[i], result);
            }
            else {
                break;
            }
        }
        return result >= n-1;
    }
};