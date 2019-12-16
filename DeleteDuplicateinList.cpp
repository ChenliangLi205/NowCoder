/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr) return pHead;
        ListNode* cur = pHead, * prev=nullptr;
        map<int, int> node2counts;
        while(cur != nullptr)
        {
            if(node2counts.find(cur->val) == node2counts.end())
                node2counts[cur->val] = 1;
            else
                node2counts[cur->val]++;
            cur = cur->next;
        }
        cur = pHead;
        while(cur!=nullptr)
        {
            if(node2counts[cur->val] > 1)
            {
                if(prev == nullptr)
                {
                    pHead = cur->next;
                    cur = cur->next;
                    continue;
                }
                else
                {
                    prev->next = cur->next;
                    cur = cur->next;
                    continue;
                }
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return pHead;
    }
};