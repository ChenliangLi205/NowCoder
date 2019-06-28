/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtreeHelper1(TreeNode* r1, TreeNode* r2)
    {
        if(r2==nullptr) return true;
        if(r1==nullptr) return false;
        if(r1->val != r2->val) return false;
        else return HasSubtreeHelper1(r1->left, r2->left) &&
            HasSubtreeHelper1(r1->right, r2->right);
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        bool success=false;
        if(pRoot1->val == pRoot2->val)
            success = HasSubtreeHelper1(pRoot1, pRoot2);
        if(!success) success = HasSubtree(pRoot1->left, pRoot2);
        if(!success) success = HasSubtree(pRoot1->right, pRoot2);
        return success;
    }
};