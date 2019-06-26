/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<vector>
#include<assert.h>
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        assert(pre.size() == vin.size());
        if(pre.empty() || vin.empty()) return nullptr;
        TreeNode* root = new TreeNode(pre[0]);
        if(pre.size() > 1)
        {
            std::vector<int> leftPre, rightPre, leftVin, rightVin;
            int preIter = 1, vinIter = 0;
            while(pre[0] != vin[vinIter])
            {
                leftVin.push_back(vin[vinIter++]);
                leftPre.push_back(pre[preIter++]);
            }
            vinIter++;
            while(vinIter<vin.size() && preIter<pre.size())
            {
                rightPre.push_back(pre[preIter++]);
                rightVin.push_back(vin[vinIter++]);
            }
            root->left = reConstructBinaryTree(leftPre, leftVin);
            root->right = reConstructBinaryTree(rightPre, rightVin);
        }
        return root;
    }
};