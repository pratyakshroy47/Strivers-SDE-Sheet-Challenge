/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
vector<vector<int>> ret;
if (root == nullptr) return ret;
queue<pair<TreeNode*, int>> q;
q.emplace(root, 0);
while (!q.empty()) {
int n = q.size();
vector<int> level;
int depth = q.front().second;
for (int i = 0; i < n; ++i) {
pair<TreeNode*, int> cur = q.front(); q.pop();
level.push_back(cur.first->val);
if (cur.first->left) q.emplace(cur.first->left, cur.second + 1);
if (cur.first->right) q.emplace(cur.first->right, cur.second + 1);
}
if (depth % 2 != 0) reverse(level.begin(), level.end());
ret.push_back(level);
}
return ret;
}
};