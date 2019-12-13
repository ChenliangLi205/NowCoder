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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == nullptr) return true;
        if(pRoot->left == nullptr && pRoot->right == nullptr) return true;
        vector<TreeNode*> thisLevel, nextLevel;
        nextLevel.push_back(pRoot);
        while(!AllNull(nextLevel))
        {
            for(TreeNode* n : nextLevel) thisLevel.push_back(n);
            nextLevel.clear();
            if(!isSymmetricalLevel(thisLevel)) return false;
            for(TreeNode* n : thisLevel)
            {
                if(n == nullptr) continue;
                nextLevel.push_back(n->left);
                nextLevel.push_back(n->right);
            }
            thisLevel.clear();
        }
        return true;
    }
    bool isSymmetricalLevel(const vector<TreeNode*>& v)
    {
        if(v.empty()) return true;
        stack<TreeNode*> s;
        queue<TreeNode*> q;
        for(TreeNode* n : v)
        {
            s.push(n);
            q.push(n);
        }
        while(!s.empty() && !q.empty())
        {
            TreeNode* s_node = s.top();
            TreeNode* q_node = q.front();
            if(s_node == nullptr && q_node != nullptr) return false;
            else if(q_node == nullptr && s_node != nullptr) return false;
            else if(q_node != nullptr && s_node != nullptr && q_node->val != s_node->val)
                return false;
            s.pop();
            q.pop();
        }
        return true;
    }
    bool AllNull(const vector<TreeNode*>& v)
    {
        if(v.empty()) return true;
        for(TreeNode* n: v)
        {
            if(n != nullptr) return false;
        }
        return true;
    }
};