/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        ListNode *Pre = pHead;
        ListNode *After = pHead;
        for(int i = 0;i <= (k-1);i++){
            if(Pre == nullptr){
                return nullptr;
            }
            Pre = Pre->next;
        }
        //now, Pre is the K-th element in link (start from 0)
        while(Pre != nullptr){
            Pre = Pre->next;
            After = After->next;
        }
        //now, After is the last K-th element in link 
        return After;
        
    }
};