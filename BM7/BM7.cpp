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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *visualNode = new ListNode(0);
        visualNode->next = pHead;
        if(pHead == nullptr){
            return NULL;
        }
        ListNode* Fast = visualNode;
        ListNode* Low = visualNode;
        ListNode* nxtFast = nullptr;
        int flag = 0;
        while(1){
            if(Fast == nullptr){
                return NULL;
            }
            nxtFast = Fast->next;
            if(nxtFast == nullptr){
                return NULL;
            }
            Fast = nxtFast->next;
            Low = Low->next;
            if(Fast == Low){
                flag = 1;
                break;
            }
        }
        // have comfirmed that there is a loop
        Fast = visualNode;
        nxtFast = nullptr;
        while(1){
            Fast = Fast->next;
            Low = Low->next;
            if(Low == Fast){
                return Low;
            }
        }
    }
};