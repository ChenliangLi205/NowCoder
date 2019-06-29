/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include<queue>
#include<algorithm>
class Solution {
public:
    int sum(const vector<int>& v)
    {
        int s=0;
        for(int i : v) s+=i;
        return s;
    }
    
    bool longer(vector<int>&& v1, vector<int>&& v2)
    {
        return v1.size()>v2.size();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        if(root==nullptr) return res;
        queue<vector<int>> pathQueue;
        queue<pair<TreeNode*, TreeNode*>> kidsQueue;
        vector<int> startPath={root->val};
        pair<TreeNode*, TreeNode*> startKids = make_pair(root->left, root->right);
        pathQueue.push(startPath);
        kidsQueue.push(startKids);
        while(!pathQueue.empty() && !kidsQueue.empty())
        {
            startPath = pathQueue.front();
            pathQueue.pop();
            startKids = kidsQueue.front();
            kidsQueue.pop();
            if(startKids.first==nullptr && startKids.second==nullptr)
            {
                if(sum(startPath)==expectNumber) res.push_back(startPath);
                continue;
            }
            if(startKids.first!=nullptr)
            {
                vector<int> newPath(startPath.begin(),startPath.end());
                newPath.push_back(startKids.first->val);
                pathQueue.push(newPath);
                kidsQueue.push(make_pair(startKids.first->left,
                                         startKids.first->right));
            }
            if(startKids.second!=nullptr)
            {
                vector<int> newPath(startPath.begin(), startPath.end());
                newPath.push_back(startKids.second->val);
                pathQueue.push(newPath);
                kidsQueue.push(make_pair(startKids.second->left,
                                         startKids.second->right));
            }
        }
        sort(res.begin(), res.end(),
             [](vector<int> v1, vector<int> v2){return v1.size() > v2.size();});
        return res;
    }
};