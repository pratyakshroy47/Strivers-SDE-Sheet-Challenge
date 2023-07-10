class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int positiveCount = 0;
        int negativeCount = 0;
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                positiveCount++;
            }
            else if(nums[i]<0){
                negativeCount++;
            }
        }
        return positiveCount > negativeCount ? positiveCount : negativeCount;
    }
};