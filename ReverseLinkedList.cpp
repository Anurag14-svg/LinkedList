class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL; 
        ListNode* curr = head;
        ListNode* next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            
        }
        
        return prev;
        
        
    }
};


// We are just changing the links here from current to prev also keep track of the next node otherwise we will lost the original linked list
// And then making curr -> prev and next -> curr we will moce like this 
// At the end we will return prev as it will be our head node
