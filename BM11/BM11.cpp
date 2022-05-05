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
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* reverse(ListNode *list){
        if(list == nullptr){
            return list;
        }
        ListNode *visual = new ListNode(0);
        visual->next = list;
        ListNode *index = list;
        ListNode *nxt = list->next;
        list->next = nullptr;
        ListNode *nxt2 = nullptr;
        while(nxt != nullptr){
            nxt2 = nxt->next;
            nxt->next = index;
            //update
            index = nxt;
            nxt = nxt2;
            //cout << index->val << endl;
        }
        visual->next = index;
        return visual->next;
    }

    
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        ListNode *REhead1 = reverse(head1);
        ListNode *REhead2 = reverse(head2);
        //exit(0);
        ListNode *index1 = REhead1;
        ListNode *index2 = REhead2;
        ListNode *head = new ListNode(-1);
        ListNode *index = head;
        int carry = 0;
        int sum = 0;
        int flag = -1;
        //cout << "hello" << endl;
        //exit(0);
        while(1){
            index->next = new ListNode(-1);
            index = index->next;
            sum = 0;
            sum = index1->val + index2->val + carry;
            carry = 0;
            if(sum >= 10){
                carry = 1;
                sum = sum - 10;
            }
            index->val = sum;
            index1 = index1->next;
            index2 = index2->next;
            if(index1 == nullptr && index2 == nullptr){
                flag = 0;
                break;
            }
            else if(index1 == nullptr){
                flag = 1;
                break;
            }
            else if(index2 == nullptr){
                flag = 2;
                break;
            }
            else{
                continue;
            }
        }
        int value = 0;
        //cout << "hello" << endl;
        //exit(0);
        if(flag == 1){
            while(carry != 0 && index2 != nullptr){
                value = index2->val + carry;
                carry = 0;
                if(value >= 10){
                    carry = 1;
                    value -= 10;
                }
                index->next = new ListNode(value);
                index = index->next;
                index2 = index2->next;
                if(index2 == nullptr && carry == 1){
                    index->next = new ListNode(1);
                    break;
                }
            }
            if(index2 != nullptr){
                index->next = index2;
            }
        }
        if(flag == 2){
            while(carry != 0 && index1 != nullptr){
                value = index1->val + carry;
                carry = 0;
                if(value >= 10){
                    carry = 1;
                    value -= 10;
                }
                index->next = new ListNode(value);
                index = index->next;
                index1 = index1->next;
                if(index1 == nullptr && carry == 1){
                    index->next = new ListNode(1);
                    break;
                }
            }
            if(index1 != nullptr){
                index->next = index1;
            }
        }
        ListNode *result = reverse(head->next);
        return result;
    }
};