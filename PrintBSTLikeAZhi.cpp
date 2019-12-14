/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector< vector<int> > res;
        if(pRoot==nullptr) return res;
        stack<TreeNode*> s1, s2;
        s1.push(pRoot);
        while(!s1.empty() || !s2.empty())
        {
            vector<int> thisLevel;
            if(s2.empty()) thisLevel = TraverseOneLevelByStack(s1, s2, true);
            else if(s1.empty()) thisLevel = TraverseOneLevelByStack(s2, s1, false);
            res.push_back(thisLevel);
        }
        return res;
    }
    vector<int> TraverseOneLevelByStack(stack<TreeNode*>& s_full, stack<TreeNode*>& s_empty, bool left_first)
    {
        vector<int> v;
        if(s_full.empty()) return v; 
        while(!s_full.empty())
        {
            TreeNode* n = s_full.top();
            v.push_back(n->val);
            if(left_first)
            {
                if(n->left!=nullptr) s_empty.push(n->left);
                if(n->right!=nullptr) s_empty.push(n->right);
            }
            else
            {
                if(n->right!=nullptr) s_empty.push(n->right);
                if(n->left!=nullptr) s_empty.push(n->left);
            }
            s_full.pop();
        }
        return v;
    }
    
};