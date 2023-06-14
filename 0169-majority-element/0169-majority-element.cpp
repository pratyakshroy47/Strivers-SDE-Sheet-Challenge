class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el;
        int cnt = 0;
        int cnt1 = 0;

        for(int i=0; i<n; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(el == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i]==el){
                cnt++;
            }
        }

        if(cnt > (n/2)){
            return el;
        }

        return -1;
    }
};