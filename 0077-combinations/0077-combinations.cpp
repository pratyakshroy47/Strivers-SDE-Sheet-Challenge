class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
vector<int> combination;
vector<vector<int>> ret;
vector<bool> chosen(n + 1, false);
backtrack(1, n, k, chosen, combination, ret);
return ret;
}
void backtrack(int j, int n, int k, vector<bool>& chosen, vector<int>&
combination, vector<vector<int>>& ret) {
if (combination.size() == k) ret.push_back(combination);
for (int i = j; i <= n; ++i) {
if (chosen[i] == true || (!combination.empty() && i < combination.back()))
continue;
chosen[i] = true;
combination.push_back(i);
backtrack(j + 1, n, k, chosen, combination, ret);
chosen[i] = false;
combination.pop_back();
}
}
};