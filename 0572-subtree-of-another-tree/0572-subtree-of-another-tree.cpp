class Solution {
public: 
    bool isSametree(TreeNode* a, TreeNode* b) {
        if(!a && !b) return true;
        if(!a || !b) return false;

        if(a -> val != b -> val) return false; //value mismatch
        return isSametree(a -> left,b -> left) && isSametree(a -> right,b -> right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!root) return false;

        if(isSametree(root,subRoot)) return true; //yahin sa match hoga

        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
        // nahi mila to left ya right mein dhundo
    }
};