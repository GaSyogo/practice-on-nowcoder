/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode* Fast = head;
        ListNode* Low = head;
        ListNode* nxtFast = nullptr;
        while(1){
            if(Fast == nullptr){
                return false;
            }
            nxtFast = Fast->next;
            if(nxtFast == nullptr){
                return false;
            }
            Fast = nxtFast->next;
            Low = Low->next;
            if(Fast == Low){
                return true;
            }
        }
    }
};