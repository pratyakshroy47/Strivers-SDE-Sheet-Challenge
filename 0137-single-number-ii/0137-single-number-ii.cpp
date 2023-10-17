class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto& i : nums) ++cnt[i];
        for (auto& [k, v] : cnt)
        if (v == 1)
        return k;
        return 0;
    }
};