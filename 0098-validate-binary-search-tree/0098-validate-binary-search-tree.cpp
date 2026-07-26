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
    TreeNode* prev = nullptr;   // keep track of previous node in inorder
    bool ans = true;

    void inorder(TreeNode* root) {
        if (!root || !ans) return;   // base case or early stop

        inorder(root->left);

        if (prev && root->val <= prev->val) {
            ans = false;             // violation of BST property
            return;
        }
        prev = root;

        inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
