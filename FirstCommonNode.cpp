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
    int ListLength(ListNode* head)
    {
        if(head==nullptr) return 0;
        ListNode* cur = head;
        int len = 0;
        while(cur!=nullptr)
        {
            len++;
            cur = cur->next;
        }
        return len;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr) return nullptr;
        int len1 = ListLength(pHead1), len2 = ListLength(pHead2);
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        if(len1 > len2)
        {
            for(int i=0;i<len1-len2;i++) cur1 = cur1->next;
        }
        else if(len1 < len2)
        {
            for(int i=0;i<len2-len1;i++) cur2 = cur2->next;
        }
        while(cur1 != cur2 && cur1 != nullptr && cur2 != nullptr)
        {
            cur1 = cur1 ->next;
            cur2 = cur2 ->next;
        }
        return cur1;
    }
};