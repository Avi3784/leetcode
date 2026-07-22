class Solution {
public:
   
   int diameter = 0;

   int height(TreeNode* node){
    if(node == NULL) return 0;

    int left = height(node -> left);
    int right = height(node -> right);

    diameter = max(diameter , left + right);

    return 1 + max(left , right);
   }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root); //updates diameter whenever called
        return diameter;
    }
};