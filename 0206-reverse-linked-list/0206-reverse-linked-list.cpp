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
    ListNode* reverseList(ListNode* head) {
        ListNode*curr= head;
        ListNode* prev= NULL;
        
        while(curr!=NULL){
            ListNode*next=curr->next;//saving  curr 's next elements address at next variable
            curr->next=prev;//linked curr next as prev
            ///updation 
            prev=curr;//shfitng prev pointer to currs position
            curr=next;//curr pointer to next's position

        }
        head=prev; //at last new head
        return head;
    }
};