class Solution {
public:
    int IsBalancedHelper(TreeNode* root)
    {
        if(root==nullptr) return 0;
        int leftDepth = IsBalancedHelper(root->left);
        int rightDepth = IsBalancedHelper(root->right);
        if(leftDepth == -1 || rightDepth == -1) return -1;
        int maxDepth = leftDepth > rightDepth ? leftDepth : rightDepth;
        int minDepth = leftDepth > rightDepth ? rightDepth : leftDepth;
        if(maxDepth-minDepth > 1) return -1;
        else return 1+maxDepth;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==nullptr) return true;
        int leftDepth = IsBalancedHelper(pRoot->left);
        int rightDepth = IsBalancedHelper(pRoot->right);
        if(leftDepth == -1 || rightDepth == -1) return false;
        int maxDepth = leftDepth > rightDepth ? leftDepth : rightDepth;
        int minDepth = leftDepth > rightDepth ? rightDepth : leftDepth;
        if(maxDepth-minDepth <= 1) return true;
        else return false;
    }
};