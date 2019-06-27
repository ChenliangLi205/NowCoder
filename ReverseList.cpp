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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr) return nullptr;
        if(pHead->next == nullptr) return pHead;
        ListNode* curNode = pHead;
        ListNode* nextNode = curNode -> next;
        ListNode* prevNode = nullptr;
        ListNode* newHead = nullptr;
        while(curNode!=nullptr)
        {
            if(curNode->next == nullptr)
            {
                newHead = curNode;
                curNode->next = prevNode;
                break;
            }
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        return newHead;
    }
};