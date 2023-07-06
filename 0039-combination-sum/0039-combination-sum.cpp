class Solution {
public:

    //Recursion method: 

    // void helper(vector<vector<int>>& res, vector<int>& curr, vector<int>& candidates, int& target, int curr_sum, int i){
    //     if(curr_sum == target){
    //         res.push_back(curr);
    //         return;
    //     }

    //     if(i>=candidates.size() || curr_sum>target){
    //         return;
    //     }

    //     curr.push_back(candidates[i]);
    //     helper(res, curr, candidates, target, curr_sum + candidates[i], i);

    //     curr.pop_back();

    //     if(i+1 < candidates.size()){
    //         helper(res, curr, candidates, target, curr_sum, i+1);
    //     }
    // }
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<vector<int>> res;
    //     vector<int> curr;
    //     helper(res, curr, candidates, target, 0, 0);

    //     return res;
    // }

    //DP method:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<vector<int>>> dp(target+1);
        dp[0] = {{}};
        for(int &i:candidates){
            for(int j=i; j<=target; j++){
                for(auto v:dp[j-i]){
                    v.push_back(i);
                    dp[j].push_back(v);
                }
            }
        }
        return dp[target];
    }
};