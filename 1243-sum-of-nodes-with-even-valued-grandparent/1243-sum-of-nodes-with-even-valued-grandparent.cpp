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
    int ans;

    void cal(TreeNode* root){
        if(root==NULL){
            return;
        }
        int sum = 0;
        if(root->left)
            sum += root->left->val;

        if(root->right){
            sum += root->right->val;
        }

        ans += sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
            return 0;

        if(root->val % 2 == 0){
            cal(root->left);
            cal(root->right);
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        return ans;
    }
};