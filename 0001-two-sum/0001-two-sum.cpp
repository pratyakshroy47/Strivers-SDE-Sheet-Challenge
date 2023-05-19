class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        // for(auto it : v){
        //     cout<<it.first<<" "<<it.second<<"\n";
        // }
        int l=0,r=n-1;
        vector<int> index;
        while(l<r){
            int sum = v[l].first + v[r].first;
            if(sum == target){
                index.push_back(v[l].second);
                index.push_back(v[r].second);
                return index;
            }else if(sum > target){
                r--;
            }else{
                l++;
            }
        }

        return {};
    }
};