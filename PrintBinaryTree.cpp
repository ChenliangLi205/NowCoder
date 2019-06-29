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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        vector<TreeNode*> v,newV;
        v.push_back(root);
        while(!v.empty())
        {
            newV.clear();
            for(TreeNode* n : v)
            {
                if(n!=nullptr)
                {
                    newV.push_back(n->left);
                    newV.push_back(n->right);
                    res.push_back(n->val);
                }
            }
            v = newV;
        }
        return res;
    }
};