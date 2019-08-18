#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left, * right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

TreeNode* ConstructTree(const vector<int>& Preorder, const vector<int>& Inorder)
{
    if(Preorder.empty()) return nullptr;
    TreeNode* root = new TreeNode(Preorder[0]);
    // partition the sequences into right and left
    vector<int> leftPre, rightPre, leftIn, rightIn;
    size_t root_pos = 0;
    for(;root_pos<Inorder.size();++root_pos)
    {
        if(Inorder[root_pos] == Preorder[0])
            break;
        leftIn.push_back(Inorder[root_pos]);
    }
    for(size_t i=root_pos+1;i<Inorder.size();++i)
    {
        rightIn.push_back(Inorder[i]);
    }
    for(size_t i=1;i<Preorder.size();++i)
    {
        if(i<=root_pos)
            leftPre.push_back(Preorder[i]);
        else
            rightPre.push_back(Preorder[i]);
    }
    // construct kid trees
    root->left = ConstructTree(leftPre, leftIn);
    root->right = ConstructTree(rightPre, rightIn);
    return root;
}

vector<int> InorderTraverse(TreeNode* root)
{
    vector<int> res;
    if(root == nullptr) return res;
    for(int i: InorderTraverse(root->left))
        res.push_back(i);
    res.push_back(root->val);
    for(int i: InorderTraverse(root->right))
        res.push_back(i);
    return res;
}

vector<int> PreorderTraverse(TreeNode* root)
{
    vector<int> res;
    if(root == nullptr) return res;
    res.push_back(root->val);
    for(int i: PreorderTraverse(root->left))
        res.push_back(i);
    for(int i: PreorderTraverse(root->right))
        res.push_back(i);
    return res;
}

int Transfer(TreeNode* root)
{
    if(root == nullptr) return 0;
    int prev_val = root->val;
    root->val = Transfer(root->left) + Transfer(root->right);
    return root->val + prev_val;
}

int main()
{
    vector<int> Total;
    int n;
    while(cin>>n)
    {
        Total.push_back(n);
    }
    vector<int> Pre(Total.begin(), Total.begin()+Total.size()/2);
    vector<int> In(Total.begin()+Total.size()/2, Total.end());
    TreeNode* root = ConstructTree(Pre, In);
    Transfer(root);
    vector<int> res = InorderTraverse(root);
    for(size_t i=0;i<res.size();++i)
    {
        if(i == res.size()-1) cout<<res[i]<<endl;
        else cout<<res[i]<<" ";
    }
    return 0;
}