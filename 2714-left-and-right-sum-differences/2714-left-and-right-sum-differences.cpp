class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int rightSum = 0;
        for(int i=n-1; i>=0; i--){
            ans[i] = rightSum;
            rightSum+=nums[i];
        }

        int leftSum = 0;
        for(int i=0; i<=n-1; i++){
            ans[i] = abs(ans[i] - leftSum);
            leftSum+=nums[i];
        }
        return ans;
    }
};