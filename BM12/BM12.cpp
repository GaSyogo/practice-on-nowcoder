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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    void showList(ListNode * head){
        while(head != nullptr){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    
    // merge 2 sorted lists such that the next of end of head1 is head2
    ListNode* mergeList(ListNode* head1, ListNode* head2){
        //cout << "welcome to the beginning of merge" << endl;
        if(head1 == nullptr){
            return head2;
        }
        if(head2 == nullptr){
            return head1;
        }
        ListNode* head; //result
        ListNode* index = nullptr;
        ListNode* index1 = head1;
        ListNode* index2 = head2;
        if(head1->val <= head2->val){
            head = head1;
            index1 = index1->next;
        }
        else{
            head = head2;
            index2 = index2->next;
        }
        index = head;
        while(index1 != nullptr || index2 != nullptr){
            if(index1 == nullptr){
                index->next = index2;
                index = index->next;
                index2 = index2->next;
                continue;
            }
            if(index2 == nullptr){
                index->next = index1;
                index = index->next;
                index1 = index1->next;
                continue;
            }
            if((index1->val) <= (index2->val)){
                index->next = index1;
                index = index->next;
                index1 = index1->next;
            }
            else{
                index->next = index2;
                index = index->next;
                index2 = index2->next;
            }
        }
        return head;
    }
    
    ListNode *mergeList2(ListNode* head1, ListNode* head2){
        ListNode* visual = new ListNode(0);
        ListNode* index = visual;
        while(head1 != nullptr && head2 != nullptr){
            if(head1->val <= head2->val){
                index->next = head1;
                index = index->next;
                head1 = head1->next;
            }
            else{
                index->next = head2;
                index = index->next;
                head2 = head2->next;
            }
        }
        index->next = head1 == nullptr? head2:head1;
        return visual->next;
    }
    
    ListNode* sortInList(ListNode* head) {
        //cout << "show the list head:" << endl;
        //showList(head);
        if(head == nullptr || head->next == nullptr){
            //cout << "hello1 in sort" << endl;
            return head;
        }
        ListNode* first = nullptr;
        ListNode* second = head;
        ListNode* low = head;
        ListNode* fast = head;
        while(1){
            if(fast->next == nullptr){
                break;
            }
            fast = fast->next;
            if(fast->next == nullptr){
                break;
            }
            fast = fast->next;
            //fast and low pointer
            second = low;
            low = low->next;
        }
        first = head;
        ListNode* preEnd = second;
        second = second->next;
        preEnd->next = nullptr;
        /*
        cout << "fist:";
        showList(first);
        cout << "second:";
        showList(second);
        //exit(0);
        */
        return mergeList2(sortInList(first),sortInList(second));
    }
};