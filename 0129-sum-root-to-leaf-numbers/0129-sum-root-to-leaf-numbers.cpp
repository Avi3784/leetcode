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
    int res=0;
   
    void sum(TreeNode* root ,int currsum){
        if(root==NULL){
            return ;
        }
        
        currsum=currsum*10+root->val;
        if(root->left==NULL && root->right==NULL){
            res+=currsum;
        }
        sum(root->left,currsum);
        sum(root->right,currsum);

    }
    int sumNumbers(TreeNode* root) {
        
        sum(root,0);
        return res;
    }
};