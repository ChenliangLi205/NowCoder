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
private:
    map<TreeNode*, int> node2nums;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int allNodes = NumberofNodes(pRoot), smallerNodes=0, largerNodes=0, target=k-1;
        TreeNode* cur = pRoot;
        while(cur != nullptr)
        {
            smallerNodes = 0;
            largerNodes = 0;
            if(cur->left != nullptr)
                smallerNodes = node2nums[cur->left];
            if(cur->right != nullptr)
                largerNodes = node2nums[cur->right];
            if(smallerNodes == target) break;
            else if(smallerNodes > target) cur = cur->left;
            else
            {
                cur = cur->right;
                target -= (smallerNodes+1);
            }
        }
        return cur;
    }
    int NumberofNodes(TreeNode*& root)
    {
        int res;
        if(root == nullptr) {res = 0;return res;}
        else
            res = 1 + NumberofNodes(root->left) + NumberofNodes(root->right);
        node2nums[root] = res;
        return res;
    }
};