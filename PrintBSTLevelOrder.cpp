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
            vector<vector<int> > res;
            if(pRoot == nullptr) return res;
            queue<TreeNode*> q1, q2;
            q1.push(pRoot);
            while(!q1.empty() || !q2.empty())
            {
                vector<int> thisLevel;
                if(q2.empty()) thisLevel = TraverseOneLevelByQueue(q1, q2);
                else if(q1.empty()) thisLevel = TraverseOneLevelByQueue(q2, q1);
                res.push_back(thisLevel);
            }
            return res;
        }
    
        vector<int> TraverseOneLevelByQueue(queue<TreeNode*>& q_full, queue<TreeNode*>& q_empty)
        {
            vector<int> v;
            if(q_full.empty()) return v;
            while(!q_full.empty())
            {
                TreeNode* n = q_full.front();
                v.push_back(n->val);
                if(n->left!=nullptr) q_empty.push(n->left);
                if(n->right!=nullptr) q_empty.push(n->right);
                q_full.pop();
            }
            return v;
        }
    
};