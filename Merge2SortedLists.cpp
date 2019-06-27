/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr) return pHead2;
        if(pHead2 == nullptr) return pHead1;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        ListNode* prev1 = nullptr;
        int i1, i2;
        ListNode* tmp;
        while(cur1 != nullptr)
        {
            if(cur2 == nullptr) break;
            if(cur1->val > cur2->val)
            {
                if(cur1 == pHead1)
                {
                    prev1 = cur2;
                    cur2 = cur2 -> next;
                    prev1->next = cur1;
                    pHead1 = prev1;
                    continue;
                }
                else
                {
                    prev1->next = cur2;
                    tmp = cur2->next;
                    cur2->next = cur1;
                    cur2 = tmp;
                    prev1 = prev1->next;
                    continue;
                }
            }
            prev1 = cur1;
            cur1 = cur1->next;
        }
        if(cur1==nullptr)
            prev1 -> next = cur2;
        return pHead1;
    }
};