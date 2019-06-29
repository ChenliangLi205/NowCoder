/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
#include<map>
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==nullptr) return nullptr;
        map<RandomListNode*,RandomListNode*> old2new;
        RandomListNode* cur = pHead;
        RandomListNode* newHead = new RandomListNode(pHead->label);
        RandomListNode* newCur = newHead;
        old2new.insert(make_pair(pHead, newHead));
        while(cur!=nullptr && newCur!=nullptr)
        {
            if(cur->next!=nullptr)
            {
                newCur->next = new RandomListNode(cur->next->label);
                old2new.insert(make_pair(cur->next, newCur->next));
            }
            cur = cur->next;
            newCur = newCur->next;
        }
        cur = pHead;
        newCur = newHead;
        while(cur!=nullptr && newCur!=nullptr)
        {
            if(cur->random!=nullptr)
                newCur->random = old2new.at(cur->random);
            cur = cur->next;
            newCur = newCur->next;
        }
        return newHead;
    }
};