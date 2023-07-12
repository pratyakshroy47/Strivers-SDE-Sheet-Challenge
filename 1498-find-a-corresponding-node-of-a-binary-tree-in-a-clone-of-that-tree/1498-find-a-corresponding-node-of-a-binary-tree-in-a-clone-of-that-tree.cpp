/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;

    void Clone(TreeNode* clone, TreeNode* target){
        if(clone == NULL){
            return;
        }
        if(clone->val == target->val){
            ans = clone;
        }
        Clone(clone->left, target);
        Clone(clone->right, target);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        Clone(cloned, target);
        return ans;
    }
};