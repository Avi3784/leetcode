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
    TreeNode *prevNode = nullptr;
    TreeNode *g1first = nullptr, *g1second = nullptr;
    TreeNode *g2first = nullptr, *g2second = nullptr;
    int galat = 0;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prevNode && root->val < prevNode->val) { // violation
            if (galat == 0) {
                g1first = prevNode;
                g1second = root;
                galat++;
            } else {
                g2first = prevNode;
                g2second = root;
                galat++;
            }
        }
        prevNode = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if (galat == 1) {
            swap(g1first->val, g1second->val);
        } else if (galat == 2) {
            swap(g1first->val, g2second->val);
        }
    }
};
