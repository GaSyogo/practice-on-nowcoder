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
    ListNode* merge(ListNode* p,ListNode* q){
        if(!p||!q)return !q?p:q;//If empty, return another one directly
        ListNode *head=new ListNode(0),*s=head;
        while(p&&q){
            if(p->val<q->val){
                s->next=p;
                p=p->next;
            }else{
                s->next=q;
                q=q->next;              
            }
            s=s->next;
        }
        if(p)s->next=p;//If either has anything left, followed by new one
        else s->next=q;
        return head->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* head=NULL;
        for(int i=0;i<lists.size();i++){
            head=merge(head,lists[i]);//merge the 2 lists
        }
        return head;
    }
};