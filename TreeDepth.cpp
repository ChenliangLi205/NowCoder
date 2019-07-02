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
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == nullptr) return 0;
        int leftD = TreeDepth(pRoot->left);
        int rightD = TreeDepth(pRoot->right);
        return 1 + (leftD > rightD ? leftD : rightD);
    }
};