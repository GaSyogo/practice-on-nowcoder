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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* visualNode = new ListNode(0);
        ListNode* preEnd = visualNode;
        ListNode* index1 = pHead1;
        ListNode* index2 = pHead2;
        if(index1 == nullptr){
          return index2;
        }
        if(index2 == nullptr){
          return index1;
        }
        while((index1 != nullptr) || (index2 != nullptr)){
            //note that "index#->val" could be ilegal.
            if(index1 == nullptr){
                preEnd->next = index2;
                preEnd = index2;
                index2 = index2->next;
                continue;
            }
            if(index2 == nullptr){
                preEnd->next = index1;
                preEnd = index1;
                index1 = index1->next;
                continue;
            }
            if(index1->val <= index2->val){
                preEnd->next = index1;
                preEnd = index1;
                index1 = index1->next;
            }
            else{
                preEnd->next = index2;
                preEnd = index2;
                index2 = index2->next;
            }
        }
        return visualNode->next;
    }
};