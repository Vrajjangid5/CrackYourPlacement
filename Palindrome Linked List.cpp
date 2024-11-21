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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*second=slow->next;
        slow->next=NULL;
        ListNode*curr=second;
        ListNode*next=NULL;
        ListNode*prev=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode*start=head;
        ListNode*end=prev;
        
        while(start && end){
            if(start -> val != end -> val)
            return false;
            start = start -> next;
            end = end -> next;
        }

        return true;

    }
};
