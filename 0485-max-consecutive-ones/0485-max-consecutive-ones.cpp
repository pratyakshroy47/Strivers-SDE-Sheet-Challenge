class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int flag = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                flag++;
            }
            else{
                flag = 0;
            }
            maxi = max(maxi, flag);
        }

        return maxi;
    }
};