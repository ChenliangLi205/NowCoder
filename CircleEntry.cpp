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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //Judge if circle exists
        if(pHead == nullptr) return nullptr;
        if(pHead->next == pHead) return pHead;
        ListNode* slow = pHead;
        ListNode* fast = pHead->next;
        while(fast != slow)
        {
            if(fast == nullptr || slow == nullptr) return nullptr;
            if(fast -> next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }
        //circle length
        int CircleLength = 0;
        slow = slow -> next;
        ++CircleLength;
        while(slow != fast)
        {
            slow = slow -> next;
            ++CircleLength;
        }
        //Find Entry
        slow = pHead;
        fast = pHead;
        for(int i=0;i<CircleLength;++i)
            fast = fast->next;
        while(slow != fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};