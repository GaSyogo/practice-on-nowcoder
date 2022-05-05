/*
struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
      val(x), next(NULL) {
  }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = 0;
        int len2 = 0;
        ListNode *index = pHead1;
        while(index != nullptr){
            index = index->next;
            len1++;
        }
        index = pHead2;
        while(index != nullptr){
            index = index->next;
            len2++;
        }
        int diff = len1 - len2;
        ListNode *index1 = pHead1;
        ListNode *index2 = pHead2;
        if(diff >= 0){
            for(int i = 0; i < diff;i++){
                index1 = index1->next;
            }
            while(index1 != index2){
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
        else{
            for(int i = 0; i < (0 - diff);i++){
                index2 = index2->next;
            }
            while(index1 != index2){
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
        
        
    }
};