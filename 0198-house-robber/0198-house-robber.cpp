class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        int prev2 = 0;
        int prev = 0;

        for(int i=0; i<nums.size(); i++){
            int temp = prev;
            prev = max(prev2 + nums[i], prev);
            prev2 = temp;
        }
        return prev;
    }
};