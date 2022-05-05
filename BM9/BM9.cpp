/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *visualNode = new ListNode(0);
        visualNode->next = head;
        ListNode *Pre = head;
        ListNode *After = head;
        ListNode *After2 = visualNode;
        for(int i = 0;i <= (n-1);i++){
            if(Pre == nullptr){
                return nullptr;
            }
            Pre = Pre->next;
        }
        //now, Pre is the K-th element in link (start from 0)
        while(Pre != nullptr){
            Pre = Pre->next;
            After = After->next;
            After2 = After2->next;
        }
        // now, After is the last K-th element in link 
        // After2 is the the last (K+1)-th one
        After2->next = After->next;
        return visualNode->next;
    }
};