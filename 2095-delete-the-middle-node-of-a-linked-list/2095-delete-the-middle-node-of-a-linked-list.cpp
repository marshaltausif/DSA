/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int size(ListNode*head){
           int sz=0;
            ListNode*temp = head;
            while(temp!=NULL){
                temp=temp->next;
                sz++;
            }
            return sz;
        }


    ListNode* deleteMiddle(ListNode* head) {
        ListNode*temp=head;
        int sizeh=size(head);
        int middle =sizeh/2;
        if(sizeh == 1){
    return NULL;
}
        
        for(int i=1;i<middle;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};