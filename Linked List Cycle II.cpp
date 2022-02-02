/* Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.*/




class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow == fast){
                break;
            }
        }
        
        if(fast==NULL || fast->next == NULL){
            return NULL;
        }
        
        fast = head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        
        return fast;
    }
};
