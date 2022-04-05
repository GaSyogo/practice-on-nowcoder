/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

void printList(ListNode* head){
    int i = 0;
    ListNode* index = head;
    cout << "show the List:" << endl;
    while(index!=nullptr){
        cout << index->val << " ";
        index = index->next;
        i++;
        if(i>=6){
            exit(0);
        }
    }
}

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if(head == nullptr)
            return head;
        int size = 0;
        ListNode* index = head;
        while(index!=nullptr){
            size++;
            index = index->next;
        }
        int num = size/k;
//         cout << "num:" << num << endl;
        ListNode* visualHead = new ListNode(0);
        visualHead->next = head;
        ListNode* preSubEnd = visualHead;
        ListNode* SubEnd = nullptr;
        ListNode* SubHead = nullptr;
        index = head;
        ListNode* nxt = index->next;
        ListNode* nxt2 = nullptr;
        while(num--){
            SubEnd = index;
            for(int i = 1; i < k; i++){
                nxt2 = nxt->next;
                nxt->next = index;
                index = nxt;
                nxt = nxt2;
            }
            SubHead = index;
            //cout << "index->val:" << index->val << endl;
            preSubEnd->next = SubHead;
            SubEnd->next = nxt2;
            
            preSubEnd = SubEnd;
            index = nxt;
            nxt = nxt->next;
        }
        //printList(visualHead);
        
        return visualHead->next;
    }
};