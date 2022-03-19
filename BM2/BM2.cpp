/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newHead = head;
        ListNode* index = head;
        if(m >= 2){
            int i = 1;
            while(i < (m-1)){
                index = index->next;
                i++;
            }
            //index = m-1,i = m-1
            ListNode* m_1= index;
            index = index->next;
            i++;//index = i = m
            ListNode* subHead = index;
            ListNode* subEnd = index;
            ListNode* pre = nullptr;
            ListNode* nxt = index->next;
            while(i < n){
//                 cout << "index->val:" << index->val << endl;
                i++;
                pre = index;
                index = nxt;
                nxt = index->next;
                
                index->next = pre;
            }
            subHead = index;
            m_1->next = subHead;
            index = nxt;
            subEnd->next = index;
        }
        else{ //m=1;
            int i = 1;
            //index = i = 1
            ListNode* subEnd = index;
            ListNode* pre = nullptr;
            ListNode* nxt = index->next;
            while(i < n){
//                 cout << "index->val:" << index->val << endl;
                i++;
                pre = index;
                index = nxt;
                nxt = index->next;
                
                index->next = pre;
            }
            newHead = index;
            index = nxt;
            subEnd->next = index;
        }
//         int j = 1;
//         while(newHead!=nullptr){
//             cout << "Node->val:" << Node->val << endl;
//             Node = Node->next;
//             j++;
//             if(j>=6){
//                 exit(0);
//             }
//         }
        return newHead;
    }
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // create a virtual header
        ListNode* zero = new ListNode(0);
        zero->next = head;
        int i = 0;
        ListNode* index = zero;
        while(i < (m-1)){
            i++;
            index = index->next;
        }
        // index = i = m -1
        ListNode* m_1 = index;
        i++;
        index = index->next;
        // index = i = m
        ListNode* subHead = index;
        ListNode* subEnd = index;
        ListNode* pre = nullptr;
        ListNode* nxt = index->next;
        while(i < n){
            i++;
            pre = index;
            index = nxt;
            nxt = index->next;

            index->next = pre;
        }
        // index = i = n
        subHead = index;
        m_1->next = subHead;
        subEnd->next = nxt;
        return zero->next;
        
    }
};