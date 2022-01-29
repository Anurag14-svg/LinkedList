class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode*  odd = head; ListNode* even = head->next;
        
        while(even && even->next){
            odd->next = odd->next->next;
            even -> next = even->next->next;
            odd= odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        return head;
    }
    
    
};
