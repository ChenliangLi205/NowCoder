/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr) return nullptr;
        TreeLinkNode* NextNode = nullptr;
        //Right kid exists
        if(pNode->right != nullptr)
        {
            //find the left most kid
            NextNode = pNode->right;
            while(NextNode->left != nullptr)
                NextNode = NextNode -> left;
        }
        //Right kids do not exist
        else
        {
            //does not have parent
            if(pNode -> next == nullptr) NextNode = nullptr;
            //self is parent's left kid
            else if(pNode->next->left == pNode)
                NextNode = pNode->next;
            //self is parent's right kid
            else
            {
                //find the closest ancestor that is the left kid
                NextNode = pNode->next;
                while(NextNode->next!=nullptr && NextNode->next->left != NextNode)
                {
                    NextNode = NextNode->next;
                }
                if(NextNode->next == nullptr) NextNode = nullptr;
                else NextNode = NextNode->next;
            }
        }
        return NextNode;
    }
};