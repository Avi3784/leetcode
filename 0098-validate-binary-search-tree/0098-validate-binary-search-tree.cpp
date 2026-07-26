class Solution {
public:
    void pt(TreeNode* node, vector<int> &ans){
        if(node==NULL){
            return;
        }
        pt(node->left, ans);
        ans.push_back(node->val);
        pt(node->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        pt(root,ans);
        int j=1;
        for(int i=1; i<ans.size(); i++){
            if(ans[i]<=ans[i-1]){
                j=0;
                break;
            }
        }
        return j;
    }
};