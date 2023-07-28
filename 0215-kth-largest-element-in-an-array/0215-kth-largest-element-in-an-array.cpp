class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxi;
        int flag = 1;
        for(auto i:nums)
            maxi.push(i);

        for(int i=0; i<nums.size(); i++){
            if(flag<k){
                maxi.pop();
                flag++;
            }
        }

        return maxi.top();
    }
};