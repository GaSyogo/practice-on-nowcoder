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
    ListNode* merge2(ListNode* p,ListNode* q){
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
    //idea of divide and conquer
    ListNode *merge(vector<ListNode *> &lists, int left, int right){
        if(left == right) return lists[left];
        if(left > right) return nullptr;
        int mid = (left + right) / 2;
        return merge2(merge(lists,left,mid),merge(lists,(mid+1),right));
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int length = lists.size();
        return merge(lists, 0,(length -1 ));
    }
};