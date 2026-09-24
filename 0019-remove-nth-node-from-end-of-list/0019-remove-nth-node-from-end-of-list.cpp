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
        
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int sizeh=size(head);
        ListNode*prev = head ;
          if (n == sizeh) {
            return head->next;
        }
        for(int i=1;i<sizeh-n;i++){
            prev=prev->next;
        }
        prev->next = prev->next->next;

        return head;
    }
   
};