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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr) return nullptr;
        TreeNode* leftStart = Convert(pRootOfTree->left);
        TreeNode* cur = leftStart;
        if(cur==nullptr) leftStart = pRootOfTree;
        else
        {
            while(cur->right!=nullptr) cur = cur->right;
            cur->right = pRootOfTree;
            pRootOfTree->left = cur;
        }
        TreeNode* rightStart = Convert(pRootOfTree->right);
        pRootOfTree->right = rightStart;
        if(rightStart!=nullptr) rightStart->left = pRootOfTree;
        return leftStart;
    }
};